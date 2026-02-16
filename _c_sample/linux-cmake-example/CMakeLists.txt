# 代码来源: 嵌入式必备工具：CMake的使用套路！
# https://mp.weixin.qq.com/s/xEJfzBBRG-v15lStW7WwhQ

cmake_minimum_required(VERSION 3.10)
project(LinuxSystem C)

# 设置编译选项
set(CMAKE_C_STANDARD 11)
add_compile_options(
  -Wall -Wextra -Werror
  -O2
)

# 添加子目录
add_subdirectory(lib)
add_subdirectory(app)

# 测试目标
enable_testing()
add_subdirectory(test)  