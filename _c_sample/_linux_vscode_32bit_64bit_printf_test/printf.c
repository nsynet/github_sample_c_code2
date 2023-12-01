//gcc -Wall  printf.c

#include <stdio.h>
#include <stdint.h> // For int64_t

int main()
{
    int32_t i = 12;
    uint32_t j =34;
    int64_t k= -56;
    uint64_t l=7890;
    
#if __WORDSIZE == 64
    #warning "64bit compile"
    printf("line=%d,%d,%u,%ld,%lu\n",__LINE__,i,j,k,l);              //64位整形在64位机器上应该是%ld
#else
    #warning "32bit compile"
    printf("line=%d,%d,%u,%lld,llu\n",__LINE__,i,j,k,l);    //64位整形在32位机器上就应该是%lld
#endif

    return 0;
}