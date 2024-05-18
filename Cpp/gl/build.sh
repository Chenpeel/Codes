#!/bin/bash

# 编译命令
gcc -I/opt/homebrew/Cellar/glfw/3.4/include \
    -I/opt/homebrew/Cellar/glad/include \
    -L/opt/homebrew/Cellar/glfw/3.4/lib \
    -lglfw.3 -framework OpenGL \
    -lpthread -ldl -lc++ \
    test.cpp /opt/homebrew/Cellar/glad/src/glad.c \
    -o test

./test

rm ./test