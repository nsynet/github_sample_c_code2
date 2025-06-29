# 设置CMake最低版本要求
cmake_minimum_required(VERSION 3.5)

# 设置项目名称和使用的语言
project(HelloWorld C)

# 添加可执行文件
add_executable(hello_world src/main.c)

# 设置C标准版本(可选)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
