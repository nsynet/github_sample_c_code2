#include <stdio.h>

#define VALUE_TO_STR(x) \
    case x:                \
        return (#x);
        
enum type_val
{
    ENUM_TYPE_NULL = 0,
    ENUM_TYPE_DEPRECATED = 1,
    ENUM_TYPE_OCTEON_SAMPLE = 2,
    ENUM_TYPE_MAX
};

static inline const char *enum_to_string(enum type_val val)
{
    switch (val)
    {
        VALUE_TO_STR(ENUM_TYPE_NULL)
        VALUE_TO_STR(ENUM_TYPE_DEPRECATED)
        VALUE_TO_STR(ENUM_TYPE_OCTEON_SAMPLE)
        VALUE_TO_STR(ENUM_TYPE_MAX)
    }
    return "Unsupported value!";
}


int main()
{
    enum type_val a;

    while (1)
    {
        printf("input(0~3):");
        scanf("%d", &a);
        if (a < ENUM_TYPE_NULL || a > ENUM_TYPE_MAX)
        {
            printf("error,you must input number between 0 and 3,please try again!\n\n");
            continue;
        }
        printf("\n");
        printf("the result:%s \n\n", enum_to_string(a));
    }

    return 0;
}
