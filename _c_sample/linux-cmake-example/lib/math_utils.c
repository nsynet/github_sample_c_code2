#include "math_utils.h"

long long factorial(int n) {
    if (n < 0)
        return -1; // 错误处理

    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}  