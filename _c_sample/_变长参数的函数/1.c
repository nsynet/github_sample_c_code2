/*
C语言的变长参数函数允许函数接受可变数量的参数，并通过使用stdarg.h头文件中提供的函数来访问它们。
*/

#include <stdarg.h>

#include <stdio.h>

void printValues(int num, ...) {

  va_list args;
  
  va_start(args, num);
  
  for (int i = 0; i < num; i++) {
  
    int value = va_arg(args, int); // 从可变参数列表中获取参数值
  
    printf("%d ", value);
  
  }
  
  va_end(args);

}

int main() {
  printValues(3, 1, 2, 3); // 输出：1 2 3
  printf("\n");
  printValues(7, 1, 2, 3 ,4 ,5 ,6 ,7); // 输出：1 2 3
}