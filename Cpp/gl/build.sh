#!/bin/bash
gcc -I/opt/homebrew/Cellar/glfw/3.4/include \
    -I/opt/homebrew/Cellar/glad/include \
    -I/opt/homebrew/Cellar/glm/include \
    -I/opt/homebrew/Cellar/freeglut/3.4.0/include \
    -L/opt/homebrew/Cellar/freeglut/3.4.0/lib \
    -L/opt/homebrew/Cellar/glfw/3.4/lib \
    -lglfw.3 -lglut -framework OpenGL \
    -lpthread -ldl -lc++ \
    -DGL_SILENCE_DEPRECATION \
    test.cpp \
    -o test


chmod +x test
./test

rm ./test
