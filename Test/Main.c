#include "./Headers/Header.h"

const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_QiuckSort),
};



int main(void)
{

    return cmocka_run_group_tests(tests, NULL, NULL);

}