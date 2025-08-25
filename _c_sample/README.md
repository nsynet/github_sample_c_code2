
## _c_sample


## __attribute__((cleanup(my_free)))特性_devcpp工程
## _coredump_test/
## _devcpp_print_macro_when_compile/

[编译时打印出宏的实际值](_devcpp_print_macro_when_compile/main.c)

## _linux_vscode__print_enum_string_by_enum_value/

[打印出枚举值的字符串](_linux_vscode__print_enum_string_by_enum_value/_print_enum_string_by_enum_value.c)

参考代码:
```
#include <stdio.h>

#define STR1(a)             #a	//以“#”的形式将输入转换成字符串,必须以宏定义的方式，直接加#编译报错！

int main(int argc, char** argv)
{
    printf("print string: %s\r\n", STR1(test string));
    printf("print string: %s\r\n", STR1(10086));
    //printf("print string: %s\r\n", #10086);//必须用上面宏定义的方式，直接加#编译报错！！！
    
    return 0;
}
```
执行结果:
```
C:\Users\nisy_tc\Documents\_Dev_Cpp\hello_world1>hello_world1.exe
print string: test string
print string: 10086
```



## _linux_vscode_32bit_64bit_printf_test/

[32/64 bit的printf打印区别](_linux_vscode_32bit_64bit_printf_test/printf.c)

## _linux_vscode_fd_set/

 [fd_set()测试](_linux_vscode_fd_set/main.c) 

## _linux_vscode_fread/

[fread读取字符串文件(文件大小未知)](_linux_vscode_fread/fread_read_test1.c)

[fread读取数据结构体文件(文件大小已知)](_linux_vscode_fread/fread_read_test2.c)

## _linux_vscode_hello_world_and_analysis_in_procfs/
## _linux_vscode_ncurses_test_bar-menu/

[ncurses库测试](_linux_vscode_ncurses_test_bar-menu/bar-menu.c)

## _linux_vscode_on_linux_for_debug_c/
## _linux_vscode_process_bar/

[C语言实现的进度条](_linux_vscode_process_bar/process_bar.c)

## _makefile_链接动态库和静态库的范例/
## _变长参数的函数/
## _使用inih库解析.ini配置文件/
## common_embed_c_code.c

[C语言嵌入式软件常用](embed_c_code.c)

## list示例(running_linux_chapter_2_basic_lab2_linux用户态)
## 红黑树示例(running_linux_chapter_2_basic_lab3)

## 其他git仓的参考代码

[使用getopt_long来处理输入的选项的处理（来自《Advanced Linux Programming》）](https://github.com/yuzhidi/AdvancedLinuxProgramming/blob/master/chapter-2/getopt_long.c)