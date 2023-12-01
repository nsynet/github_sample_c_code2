#include <stdio.h>

#define STR1(a)             #a	//以“#”的形式将输入转换成字符串,必须以宏定义的方式，直接加#编译报错！

int main(int argc, char** argv)
{
    printf("print string: %s\r\n", STR1(test string));
    printf("print string: %s\r\n", STR1(10086));
    //printf("print string: %s\r\n", #10086);//必须用上面宏定义的方式，直接加#编译报错！！！
    
    return 0;
}
