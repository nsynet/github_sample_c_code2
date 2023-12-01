# sample_c_code

## 常用C语言参考代码

- [fd_set()测试](_linux_vscode_fd_set/main.c) 
- [ncurses库测试](_linux_vscode_ncurses_test_bar-menu/bar-menu.c)
- [编译时打印出宏的实际值](_devcpp_print_macro_when_compile/main.c)
- [打印出枚举值的字符串](_linux_vscode__print_enum_string_by_enum_value/_print_enum_string_by_enum_value.c)
- [fread读取数据结构体文件(文件大小已知)](_linux_vscode_fread/fread_read_test2.c)
- [fread读取字符串文件(文件大小未知)](_linux_vscode_fread/fread_read_test1.c)
- [使用getopt_long来处理输入的选项的处理（来自《Advanced Linux Programming》）](https://github.com/yuzhidi/AdvancedLinuxProgramming/blob/master/chapter-2/getopt_long.c)
- [C语言实现的进度条](_linux_vscode_process_bar/process_bar.c)
- [32/64 bit的printf打印区别](_linux_vscode_32bit_64bit_printf_test/printf.c)
- [C语言嵌入式软件常用](embed_c_code.c)


## 典型的参考代码
### linux driver开发
//奔跑吧的代码：
benshushu.coding.net/public/runninglinuxkernel_5.0/runninglinuxkernel_5.0/git/files/rlk_5.0/kmodules/rlk_lab
其中:

最小ko参考 https://benshushu.coding.net/public/runninglinuxkernel_5.0/runninglinuxkernel_5.0/git/files/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_5_module/lab1_simple_module
最简单字符设备ko参考
https://benshushu.coding.net/public/runninglinuxkernel_5.0/runninglinuxkernel_5.0/git/files/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_6_device_driver/lab1_simple_driver
最简单misc类型的字符设备ko参考
https://benshushu.coding.net/public/runninglinuxkernel_5.0/runninglinuxkernel_5.0/git/files/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_6_device_driver/lab3_mydemo_dev

### linux 用户态代码

fork-clone参考
https://benshushu.coding.net/public/runninglinuxkernel_5.0/runninglinuxkernel_5.0/git/files/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_8_process/lab1

pthread参考
https://github.com/yuzhidi/AdvancedLinuxProgramming/blob/master/chapter-4/thread-create2.c