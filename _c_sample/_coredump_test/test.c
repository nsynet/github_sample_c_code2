#include <stdio.h>  
  
int square(int a, int b) {  
    int *p = NULL;  
    *p = 666; // 这里会导致程序出错并产生coredump文件  
    return 0;  
}  
  
int main() {  
    square(1, 2);  
    return 0;  
}