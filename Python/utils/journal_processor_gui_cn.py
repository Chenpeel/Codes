#!/usr/bin/env python3
"""
期刊 PDF 文本提取工具 - 中文图形界面版本
从期刊 PDF 文件中提取纯净的英文文本
"""

import os
import re
import zipfile
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from pathlib import Path
from typing import List
import threading

try:
    import PyPDF2
except ImportError:
    PyPDF2 = None


class JournalProcessorGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("期刊 PDF 文本提取工具")
        self.root.geometry("700x600")
        self.root.resizable(False, False)

        # 窗口居中
        self.root.update_idletasks()
        width = self.root.winfo_width()
        height = self.root.winfo_height()
        x = (self.root.winfo_screenwidth() // 2) - (width // 2)
        y = (self.root.winfo_screenheight() // 2) - (height // 2)
        self.root.geometry(f'{width}x{height}+{x}+{y}')

        # 变量
        self.input_path = tk.StringVar()
        self.output_path = tk.StringVar()
        self.processing = False

        self.setup_ui()

    def setup_ui(self):
        # 配置颜色
        self.root.configure(bg='#f0f0f0')

        # 主框架
        main_frame = tk.Frame(self.root, bg='#f0f0f0', padx=30, pady=20)
        main_frame.pack(fill=tk.BOTH, expand=True)

        # 标题
        title_frame = tk.Frame(main_frame, bg='#f0f0f0')
        title_frame.pack(pady=(0, 10))

        title_label = tk.Label(title_frame, text="📄 期刊 PDF 文本提取工具",
                               font=('PingFang SC', 20, 'bold'), bg='#f0f0f0', fg='#2c3e50')
        title_label.pack()

        # 描述
        desc_label = tk.Label(main_frame,
                              text="从期刊 PDF 文件中提取纯净的英文文本\n（自动移除数字、数学符号和特殊字符）",
                              font=('PingFang SC', 10), bg='#f0f0f0', fg='#555', justify=tk.CENTER)
        desc_label.pack(pady=(0, 25))

        # 输入部分
        input_frame = tk.LabelFrame(main_frame, text=" 步骤 1：选择输入文件夹（包含 ZIP 文件） ",
                                    font=('PingFang SC', 11, 'bold'), bg='#f0f0f0', fg='#2980b9',
                                    padx=15, pady=10)
        input_frame.pack(fill=tk.X, pady=(0, 15))

        input_path_frame = tk.Frame(input_frame, bg='#f0f0f0')
        input_path_frame.pack(fill=tk.X)

        tk.Entry(input_path_frame, textvariable=self.input_path, font=('PingFang SC', 10),
                 width=45, relief=tk.SOLID, borderwidth=1).pack(side=tk.LEFT, padx=(0, 10), ipady=5)
        tk.Button(input_path_frame, text="📁 浏览", command=self.select_input_folder,
                  font=('PingFang SC', 10, 'bold'), bg='#3498db', fg='white',
                  relief=tk.FLAT, padx=15, pady=5, cursor='hand2').pack(side=tk.LEFT)

        # 输出部分
        output_frame = tk.LabelFrame(main_frame, text=" 步骤 2：选择输出文件保存位置 ",
                                     font=('PingFang SC', 11, 'bold'), bg='#f0f0f0', fg='#2980b9',
                                     padx=15, pady=10)
        output_frame.pack(fill=tk.X, pady=(0, 20))

        output_path_frame = tk.Frame(output_frame, bg='#f0f0f0')
        output_path_frame.pack(fill=tk.X)

        tk.Entry(output_path_frame, textvariable=self.output_path, font=('PingFang SC', 10),
                 width=45, relief=tk.SOLID, borderwidth=1).pack(side=tk.LEFT, padx=(0, 10), ipady=5)
        tk.Button(output_path_frame, text="💾 另存为", command=self.select_output_file,
                  font=('PingFang SC', 10, 'bold'), bg='#3498db', fg='white',
                  relief=tk.FLAT, padx=15, pady=5, cursor='hand2').pack(side=tk.LEFT)

        # 进度条
        self.progress = ttk.Progressbar(main_frame, mode='indeterminate', length=550)
        self.progress.pack(pady=(10, 10))

        # 状态标签
        self.status_label = tk.Label(main_frame, text="✓ 就绪，可以开始处理",
                                      font=('PingFang SC', 10, 'bold'), bg='#f0f0f0', fg='#27ae60')
        self.status_label.pack(pady=5)

        # 处理按钮
        self.process_btn = tk.Button(main_frame, text="▶ 开始处理",
                                      command=self.start_processing,
                                      font=('PingFang SC', 14, 'bold'), bg='#27ae60', fg='white',
                                      relief=tk.FLAT, padx=50, pady=15, cursor='hand2',
                                      activebackground='#229954')
        self.process_btn.pack(pady=20)

        # 信息标签
        info_frame = tk.Frame(main_frame, bg='#fff3cd', relief=tk.SOLID, borderwidth=1)
        info_frame.pack(fill=tk.X, pady=(10, 0))

        info_text = "ℹ️ 支持格式：包含 PDF 文档的 ZIP 文件 | 输出：仅保留纯净英文文本"
        tk.Label(info_frame, text=info_text, font=('PingFang SC', 9),
                 bg='#fff3cd', fg='#856404', pady=8).pack()

    def select_input_folder(self):
        folder = filedialog.askdirectory(title="选择包含 ZIP 文件的输入文件夹")
        if folder:
            self.input_path.set(folder)
            # 自动建议输出路径
            if not self.output_path.get():
                parent_dir = str(Path(folder).parent)
                suggested_output = os.path.join(parent_dir, "output", "result.txt")
                self.output_path.set(suggested_output)

    def select_output_file(self):
        file = filedialog.asksaveasfilename(
            title="选择输出文件保存位置",
            defaultextension=".txt",
            filetypes=[("文本文件", "*.txt"), ("所有文件", "*.*")]
        )
        if file:
            self.output_path.set(file)

    def update_status(self, message, color='black'):
        self.status_label.config(text=message, foreground=color)
        self.root.update()

    def start_processing(self):
        if self.processing:
            return

        # 验证输入
        if not self.input_path.get():
            messagebox.showerror("错误", "请选择输入文件夹")
            return
        if not self.output_path.get():
            messagebox.showerror("错误", "请选择输出文件")
            return

        if not PyPDF2:
            messagebox.showerror("错误",
                "未安装 PyPDF2 库。\n\n"
                "请使用以下命令安装：\npip install PyPDF2")
            return

        # 在单独的线程中开始处理
        self.processing = True
        self.process_btn.config(state='disabled', text='处理中...')
        self.progress.start()

        thread = threading.Thread(target=self.process_journals)
        thread.daemon = True
        thread.start()

    def process_journals(self):
        try:
            processor = JournalProcessor(self.input_path.get(),
                                        self.output_path.get(),
                                        status_callback=self.update_status)
            processor.process_all_journals()

            self.progress.stop()
            self.processing = False
            self.process_btn.config(state='normal', text='▶ 开始处理')

            messagebox.showinfo("成功",
                f"处理完成！\n\n"
                f"输出已保存到：\n{self.output_path.get()}")

        except Exception as e:
            self.progress.stop()
            self.processing = False
            self.process_btn.config(state='normal', text='▶ 开始处理')
            messagebox.showerror("错误", f"发生错误：\n{str(e)}")


class JournalProcessor:
    def __init__(self, input_dir: str, output_file: str, status_callback=None):
        self.input_dir = Path(input_dir)
        self.output_file = Path(output_file)
        self.status_callback = status_callback

        # 常见学术论文章节关键词
        self.skip_sections = {
            'abstract', 'keywords', 'key words', 'introduction',
            'references', 'bibliography', 'acknowledgements', 'acknowledgments',
            'figure', 'fig.', 'table', 'chart', 'graph',
            'corresponding author', 'author information', 'affiliations'
        }

    def log_status(self, message, color='black'):
        if self.status_callback:
            self.status_callback(message, color)
        else:
            print(message)

    def is_header_or_metadata(self, line: str) -> bool:
        """检查是否为标题、元数据或需要跳过的部分"""
        line_lower = line.lower().strip()

        if len(line_lower) < 10:
            return True

        if line.isupper() and len(line.split()) < 6:
            return True

        for section in self.skip_sections:
            if section in line_lower:
                return True

        if re.match(r'^\[\d+\]', line_lower) or re.match(r'^\d+\.', line_lower):
            return True

        return False

    def clean_text(self, text: str) -> str:
        """仅保留英文单词（a-z、A-Z）和常见缩写，移除所有其他符号"""
        # 提取有效的英文单词和缩写
        # 匹配：字母 a-z A-Z 组成的单词，以及常见缩写如 'd 'll 's 're 等
        pattern = r"\b[a-zA-Z]+(?:'[a-zA-Z]+)*\b"
        words = re.findall(pattern, text)

        # 用单个空格连接单词
        text = ' '.join(words)

        return text.strip()

    def extract_text_from_pdf(self, pdf_path: Path) -> str:
        """从单个 PDF 文件中提取并清理文本"""
        if not PyPDF2:
            return ""

        try:
            with open(pdf_path, 'rb') as file:
                pdf_reader = PyPDF2.PdfReader(file)
                full_text = []

                for page in pdf_reader.pages:
                    text = page.extract_text()
                    if text:
                        lines = text.split('\n')
                        for line in lines:
                            if not self.is_header_or_metadata(line):
                                cleaned = self.clean_text(line)
                                if cleaned and len(cleaned) > 20:
                                    full_text.append(cleaned)

                return ' '.join(full_text)
        except Exception as e:
            self.log_status(f"处理 {pdf_path.name} 时出错：{e}", 'red')
            return ""

    def process_zip_file(self, zip_path: Path) -> List[str]:
        """从 ZIP 中提取 PDF 并处理每个文件"""
        processed_texts = []

        try:
            with zipfile.ZipFile(zip_path, 'r') as zip_ref:
                temp_dir = self.input_dir / 'temp_extract'
                temp_dir.mkdir(exist_ok=True)

                zip_ref.extractall(temp_dir)

                pdf_files = list(temp_dir.rglob('*.pdf'))
                for idx, pdf_file in enumerate(pdf_files, 1):
                    self.log_status(f"正在处理 PDF {idx}/{len(pdf_files)}：{pdf_file.name[:30]}...")
                    text = self.extract_text_from_pdf(pdf_file)
                    if text:
                        processed_texts.append(text)

                # 清理临时目录
                import shutil
                shutil.rmtree(temp_dir)

        except Exception as e:
            self.log_status(f"处理 {zip_path.name} 时出错：{e}", 'red')

        return processed_texts

    def process_all_journals(self):
        """处理输入目录中的所有 ZIP 文件并保存到输出文件"""
        if not PyPDF2:
            self.log_status("错误：需要 PyPDF2", 'red')
            return

        # 确保输出目录存在
        self.output_file.parent.mkdir(parents=True, exist_ok=True)

        all_texts = []
        zip_files = list(self.input_dir.glob('*.zip'))

        if not zip_files:
            self.log_status(f"在 {self.input_dir} 中未找到 ZIP 文件", 'orange')
            return

        self.log_status(f"找到 {len(zip_files)} 个 ZIP 文件待处理", 'blue')

        for idx, zip_file in enumerate(zip_files, 1):
            self.log_status(f"正在处理 ZIP {idx}/{len(zip_files)}：{zip_file.name}", 'blue')
            texts = self.process_zip_file(zip_file)
            all_texts.extend(texts)

        # 写入输出
        if all_texts:
            combined_text = ' '.join(all_texts)
            with open(self.output_file, 'w', encoding='utf-8') as f:
                f.write(combined_text)

            word_count = len(combined_text.split())
            self.log_status(f"成功！已处理 {len(all_texts)} 个 PDF，共 {word_count:,} 个单词", 'green')
        else:
            self.log_status("未从 PDF 中提取到文本", 'orange')


def main():
    # 检查 PyPDF2
    if not PyPDF2:
        root = tk.Tk()
        root.withdraw()
        messagebox.showerror("缺少依赖",
            "未安装 PyPDF2 库。\n\n"
            "请使用以下命令安装：\npip install PyPDF2\n\n"
            "应用程序即将关闭。")
        return

    root = tk.Tk()
    app = JournalProcessorGUI(root)
    root.mainloop()


if __name__ == '__main__':
    main()
