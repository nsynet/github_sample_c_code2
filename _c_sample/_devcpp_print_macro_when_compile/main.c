    /* main.c */
    #include <stdio.h>
     
     
     
    #define __PRINT_MACRO(x) #x
     
    #define PRINT_MACRO(x) #x"="__PRINT_MACRO(x)
     
     
     
    int main(int argc, const char *argv[])
     
    {
     
    #define TEST_MACRO 512
     
    #pragma message(PRINT_MACRO(TEST_MACRO))
     
            return 0;
     
    } 
