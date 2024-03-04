cmake_minimum_required(VERSION 3.15)
set(WRAP_VULKAN_HEADERS OFF CACHE BOOL "Disable Vulkan Headers")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.12")
project(test)
set(CMAKE_AUTOMOC ON)
# 元对象编译器
set(CMAKE_CXX_STANDARD 14)


# find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_wrap_cpp(MOC_SOURCES headers/widget.h)
# 添加源文件和头文件
add_executable(test
    src/widget.cpp
    src/main.cpp
    headers/widget.h
    ${MOC_SOURCES}
)


# 将头文件目录添加到特定目标（test）的头文件搜索路径中
target_include_directories(test PUBLIC headers)

# target_link_libraries(test PRIVATE Qt5::Widgets)
target_link_libraries(test PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)
