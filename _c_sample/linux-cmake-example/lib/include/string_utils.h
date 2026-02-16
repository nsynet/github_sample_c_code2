#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

/**
 * @brief 反转字符串
 * @param str 要反转的字符串
 * @return 反转后的字符串指针
 */
char* reverse_string(char* str);

/**
 * @brief 计算字符串中某个字符出现的次数
 * @param str 字符串
 * @param ch 要查找的字符
 * @return 字符出现的次数
 */
size_t count_char(const char* str, char ch);

#endif // STRING_UTILS_H  