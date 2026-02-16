#include "string_utils.h"
#include <string.h>

char* reverse_string(char* str) {
    if (str == NULL || *str == '\0')
        return str;

    size_t len = strlen(str);
    char* start = str;
    char* end = str + len - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

size_t count_char(const char* str, char ch) {
    size_t count = 0;
    while (*str) {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}  