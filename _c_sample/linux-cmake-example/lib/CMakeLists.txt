# 静态库 - 字符串处理
add_library(strutils STATIC
  string_utils.c
)
target_include_directories(strutils PUBLIC include)

# 动态库 - 数学计算
add_library(mathutils SHARED
  math_utils.c
)
target_include_directories(mathutils PUBLIC include)  