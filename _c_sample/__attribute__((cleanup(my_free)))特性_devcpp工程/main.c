/*
attribute ((cleanup(func))) �� GCC��GNU Compiler Collection���е�һ����������չ�������ڱ������������ʱ�Զ�����ָ������������������Զ���ȷ����Դ����ȷ�ͷźͱ����ڴ�й©������ǳ����á�

������˵��������һ����������ǰʹ�� attribute ((cleanup(func))) ʱ�����ñ��������������ʱ��GCC ���Զ�������ָ���� func �����������ñ����ĵ�ַ��Ϊ�������ݸ��ú�������������Ϳ����� func ������ִ�б�Ҫ����������������ͷ��ڴ桢�ر��ļ��ȡ�

������һ���򵥵�ʾ����չʾ�����ʹ�� attribute ((cleanup(func))) ���ԣ�
�������ʾ���У����Ƕ�����һ�� my_malloc �������ڷ����ڴ棬��������һ�� my_free ���������ͷ��ڴ档�� main �����У�����ʹ�� attribute ((cleanup(my_free))) ����������һ�� buffer ��������ʹ�� my_malloc ����Ϊ��������ڴ档�� buffer ���������������ʱ���� main ��������ʱ����GCC ���Զ����� my_free �������ͷ� buffer ��ָ����ڴ档

��Ҫע����ǣ�attribute ((cleanup(func))) �� GCC ��һ����չ���ԣ����Ǳ�׼ C ���Ե�һ���֡���ˣ���ʹ���������ʱ������Ҫȷ����Ĵ������� GCC ��֧�ָ����Եı���������ġ����⣬��Ȼ���������ĳЩ����·ǳ����ã�������ʹ�û򲻵�ʹ�ÿ��ܻᵼ�´�����������ά������ˣ���ʹ��ʱӦ�ý���Ȩ�������ס�
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
    // ʹ�� buffer ��һЩ����...  
    return 0;  
}



