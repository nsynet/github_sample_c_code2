# 设置CMake的最小版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(HelloCMake VERSION 1.0)

# 设置C语言的编译标准（可选）
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加一个可执行文件
# 指定可执行文件的名称（hello）和源文件（hello.c）
add_executable(hello hello.c)
