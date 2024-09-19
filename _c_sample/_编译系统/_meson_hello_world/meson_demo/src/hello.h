// src/main.c  
#include <stdio.h>  
  
// 假设这是从 hello.c 引入的函数  
void hello_function();  
  
int main() {  
    printf("Hello, World from main!\n");  
    hello_function();  
    return 0;  
}
