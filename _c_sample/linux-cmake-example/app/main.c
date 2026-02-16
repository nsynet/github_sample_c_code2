#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"
#include "math_utils.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* input_str = argv[1];
    int number = atoi(argv[2]);

    // 使用字符串工具
    printf("Original string: %s\n", input_str);
    char* reversed = reverse_string(strdup(input_str));
    printf("Reversed string: %s\n", reversed);
    printf("Number of 'a's: %zu\n", count_char(input_str, 'a'));
    free(reversed);

    // 使用数学工具
    printf("Factorial of %d: %lld\n", number, factorial(number));

    return EXIT_SUCCESS;
}  
