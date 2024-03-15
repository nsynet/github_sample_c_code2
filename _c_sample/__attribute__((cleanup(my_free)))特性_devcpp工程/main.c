/*
attribute ((cleanup(func))) 是 GCC（GNU Compiler Collection）中的一个编译器扩展，用于在变量作用域结束时自动调用指定的清理函数。这个特性对于确保资源的正确释放和避免内存泄漏等问题非常有用。

具体来说，当你在一个变量声明前使用 attribute ((cleanup(func))) 时，当该变量的作用域结束时，GCC 会自动调用你指定的 func 函数，并将该变量的地址作为参数传递给该函数。这样，你就可以在 func 函数中执行必要的清理操作，比如释放内存、关闭文件等。

下面是一个简单的示例，展示了如何使用 attribute ((cleanup(func))) 特性：
在上面的示例中，我们定义了一个 my_malloc 函数用于分配内存，并定义了一个 my_free 函数用于释放内存。在 main 函数中，我们使用 attribute ((cleanup(my_free))) 特性声明了一个 buffer 变量，并使用 my_malloc 函数为其分配了内存。当 buffer 变量的作用域结束时（即 main 函数返回时），GCC 会自动调用 my_free 函数来释放 buffer 所指向的内存。

需要注意的是，attribute ((cleanup(func))) 是 GCC 的一个扩展特性，并非标准 C 语言的一部分。因此，在使用这个特性时，你需要确保你的代码是用 GCC 或支持该特性的编译器编译的。此外，虽然这个特性在某些情况下非常有用，但过度使用或不当使用可能会导致代码难以理解和维护。因此，在使用时应该谨慎权衡其利弊。
*/

#include <stdio.h>  
#include <stdlib.h>  
  
void *my_malloc(size_t size) {  
    void *ptr = malloc(size);  
    if (!ptr) {  
        fprintf(stderr, "Memory allocation failed\n");  
        exit(EXIT_FAILURE);  
    }  
    return ptr;  
}  
  
void my_free(void *ptr) {  
	printf("free memory here!\n");
    free(ptr);  
}  
  
int main() {  
    void *buffer __attribute__((cleanup(my_free))) = my_malloc(100);  
    // 使用 buffer 做一些操作...  
    return 0;  
}



