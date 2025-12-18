#!/bin/bash
# 使用 Docker 在 Linux 上构建 Windows .exe

clear
echo "========================================================"
echo ""
echo "   使用 Docker 构建 Windows .exe (在 Linux 上)"
echo ""
echo "========================================================"
echo ""
echo "这将使用 Docker 容器构建 Windows 可执行文件"
echo "无需 Windows 系统！"
echo ""
echo "按 Enter 继续，或 Ctrl+C 取消..."
read

clear
echo ""
echo "[检查环境]"
echo ""

# 检查 Docker
if ! command -v docker &> /dev/null; then
    echo "✗ 未找到 Docker"
    echo ""
    echo "请先安装 Docker:"
    echo "  Ubuntu/Debian:"
    echo "    sudo apt update"
    echo "    sudo apt install docker.io"
    echo "    sudo systemctl start docker"
    echo "    sudo usermod -aG docker $USER"
    echo ""
    echo "然后重新登录或运行: newgrp docker"
    exit 1
fi

echo "✓ 找到 Docker"
echo ""

# 检查 Docker 是否可用
if ! docker ps &> /dev/null; then
    echo "✗ Docker 未运行或权限不足"
    echo ""
    echo "请运行:"
    echo "  sudo systemctl start docker"
    echo "  sudo usermod -aG docker $USER"
    echo ""
    echo "然后重新登录"
    exit 1
fi

echo "✓ Docker 可用"
echo ""

echo "[1/3] 清理旧文件..."
rm -rf dist build *.spec 2>/dev/null
echo "✓ 清理完成"
echo ""

echo "[2/3] 拉取 PyInstaller Windows 镜像..."
echo "首次运行会下载约 500MB 镜像，请耐心等待..."
docker pull cdrx/pyinstaller-windows:python3
if [ $? -ne 0 ]; then
    echo "✗ 拉取镜像失败"
    exit 1
fi
echo "✓ 镜像准备完成"
echo ""

echo "[3/3] 构建 Windows .exe..."
echo "这可能需要 2-5 分钟..."
echo ""

# 使用 Docker 构建
docker run --rm \
    -v "$(pwd):/src" \
    cdrx/pyinstaller-windows:python3 \
    "pip install PyPDF2 && pyinstaller --onefile --windowed --name=期刊文本提取工具 --clean journal_processor_gui_cn.py"

if [ $? -eq 0 ]; then
    echo ""
    echo "✓ 构建成功"
else
    echo ""
    echo "✗ 构建失败"
    exit 1
fi
echo ""

# 清理临时文件
rm -rf build *.spec 2>/dev/null

clear
echo "========================================================"
echo ""
echo "                  ✓ 构建成功！"
echo ""
echo "========================================================"
echo ""
echo "Windows 应用程序已创建："
echo ""
echo "  位置: dist/期刊文本提取工具.exe"
echo "  大小: 约 15-20 MB"
echo ""
echo "使用方法："
echo "  1. 将 .exe 文件复制到任何 Windows 电脑"
echo "  2. 双击运行（无需安装 Python！）"
echo "  3. 支持 Windows 7/8/10/11"
echo ""
echo "分发方式："
echo "  • U盘拷贝"
echo "  • 网盘分享（百度网盘、阿里云盘等）"
echo "  • 邮件发送"
echo "  • FTP/HTTP 下载"
echo ""
echo "注意："
echo "  • 首次运行可能被 Windows Defender 警告"
echo "  • 点击"更多信息" → "仍要运行"即可"
echo ""
echo "========================================================"
echo ""
echo "按 Enter 打开 dist 文件夹..."
read
xdg-open dist 2>/dev/null || nautilus dist 2>/dev/null || echo "请手动打开 dist 文件夹"
echo ""
echo "完成！"
