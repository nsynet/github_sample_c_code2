# 应用程序
add_executable(myapp
  main.c
)
target_include_directories(myapp PRIVATE include)
target_link_libraries(myapp 
  strutils 
  mathutils
  m # 链接数学库
)

# 安装规则
install(TARGETS myapp DESTINATION bin)
install(TARGETS strutils mathutils DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)  