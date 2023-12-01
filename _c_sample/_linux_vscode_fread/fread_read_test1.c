/*
From：
https://blog.csdn.net/duduniao999/article/details/80875235
 函数原型：
size_t   fread(   void   *buffer,   size_t   size,   size_t   count,   FILE   *stream   ) 
  buffer   是读取的数据存放的内存的指针（可以是数组，也可以是新开辟的空间，buffer就是一个索引）   
    size       是每次读取的字节数  
  count     是读取次数  
  strean   是要读取的文件的指针  
  例如   从文件fp里读取100个字节   可用以下语句  
   
  fread(buffer,100,1,fp)  
  fread(buffer,50,2,fp)  
  fread(buffer,1,100,fp)   
**************************************************************************************    
对读出的二进制流是不能用strlen()或者sizeof()求其长度和大小的。
**************************************************************************************

fread可以读二进制文件，有时用字符方式去读文件不能读完整个文件，但是二进制方式就可以 。
这就是因为字符方式用特定的标记结尾的，读取时只要碰到该标记就自动结束

函数fread()读取[num]个对象(每个对象大小为size(大小)指定的字节数),并把它们替换到由buffer(缓冲区)指定的数组. 数据来自给出的输入流. 函数的返回值是读取的内容数量...

使用feof()或ferror()判断到底发生哪个错误. */



#include <stdio.h>    
void main()  
    {  
        FILE *fp;  
        int size = 0;  
        char *ar ;  
      
        //二进制方式打开文件  
        fp = fopen("test1.txt","r");  
        if(NULL == fp)  
        {  
            printf("Error:Open test1.txt file fail!\n");  
            return;  
        }  
      
        //求得文件的大小  
        fseek(fp, 0, SEEK_END);  
        size = ftell(fp);  
        rewind(fp);  
      
        //申请一块能装下整个文件的空间  
        ar = (char*)malloc(sizeof(char)*size);  
      
        //读文件  
        fread(ar,1,size,fp);//每次读一个，共读size次  
      
        printf("%s",ar);  
        fclose(fp);  
        free(ar);  
      
        printf("按任意键继续");  
        getchar();  
        getchar();  
    }  