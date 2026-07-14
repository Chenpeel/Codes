#!/bin/bash

echo "🔧 安装手写签名背景去除脚本的依赖库..."

# 检查Python是否安装
if ! command -v python3 &> /dev/null; then
    echo "❌ Python3 未安装，请先安装Python3"
    exit 1
fi

echo "✅ Python3 已安装"

# 安装依赖库
echo "📦 正在安装依赖库..."

pip3 install opencv-python pillow pillow-heif numpy

echo "✅ 依赖库安装完成！"

echo ""
echo "📋 已安装的库："
echo "  - opencv-python: 图像处理"
echo "  - pillow: 图片格式支持"
echo "  - pillow-heif: HEIC格式支持"
echo "  - numpy: 数值计算"

echo ""
echo "🚀 现在可以运行脚本了："
echo "  python3 remove_signature_background.py"
