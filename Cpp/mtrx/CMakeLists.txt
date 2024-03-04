cmake_minimum_required(VERSION 3.5)

project(main)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
add_executable(main src/main.cc)

# C++ 17
target_compile_features(main PRIVATE cxx_std_17)

# 链接GLFW
find_package(OpenGL REQUIRED)
target_link_libraries(main OpenGL::GL)
find_package(glfw3 REQUIRED)
target_link_libraries(main glfw)

# 链接Eigen3
find_package(Eigen3 REQUIRED)
target_link_libraries(main Eigen3::Eigen)