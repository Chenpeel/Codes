cmake_minimum_required(VERSION 3.5)

project(main)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
add_executable(main src/main.cc)

# C++ 17
target_compile_features(main PRIVATE cxx_std_17)

# 链接 OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(main OpenGL::GL)

# 链接 GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(main glfw)

# 设置 CMAKE_MODULE_PATH 以找到 FindEigen3.cmake
set(CMAKE_MODULE_PATH "/opt/homebrew/Cellar/eigen/3.4.0_1/share/cmake/Modules" ${CMAKE_MODULE_PATH})

# 链接 Eigen3
find_package(Eigen3 REQUIRED)
target_link_libraries(main Eigen3::Eigen)
