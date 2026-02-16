#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "string_utils.h"

static void test_reverse_string(void **state) {
    (void)state;
    char str[] = "hello";
    assert_string_equal(reverse_string(str), "olleh");
}

static void test_count_char(void **state) {
    (void)state;
    const char* str = "banana";
    assert_int_equal(count_char(str, 'a'), 3);
    assert_int_equal(count_char(str, 'x'), 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_reverse_string),
        cmocka_unit_test(test_count_char),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}  
