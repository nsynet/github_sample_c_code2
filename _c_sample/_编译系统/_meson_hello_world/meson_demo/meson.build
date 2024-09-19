# 定义项目名称和版本（可选）  
project('hello_world', 'c',  
  version : '0.1',  
  default_options : ['warning_level=3', 'c_std=c11'])  
  
# 指定源代码目录  
source_dir = 'src'  
  
# 添加一个可执行文件目标  
executable('hello_world',  
  [source_dir + '/main.c', source_dir + '/hello.c'],
  install : true)  
  
# （可选）设置安装目录  
# install_dir = get_option('bindir') / 'hello_world'  
# executable('hello_world', ..., install_dir : install_dir)
