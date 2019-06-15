#include "../thirdparty/ctest.h"
#include "../src/include/training.h"
#include "../src/include/menu.h"

//Для тестов смените глобальные переменные TEST в menu.c и training.c на 1

CTEST(time, timeout)
{
    double time1 = 3;
    double time2 = 6.5;

    double result1 = timeout(time1, time2);

    const double exp1 = 3.5;

    ASSERT_DBL_NEAR(exp1, result1);
}

CTEST(action, action)
{
    const int exp = 3;

    int result = action();

    ASSERT_EQUAL(exp, result);
}

CTEST(action, action_secs)
{
    const int exp = 15;

    int result = action_secs();

    ASSERT_EQUAL(exp, result);
}

CTEST(action, choosen_action)
{
    const int exp = 2;

    int result = choosen_action(1);

    ASSERT_EQUAL(exp, result);
}

CTEST(errors, errors_calc)
{
    int dlina_text = 3;

    char arr_proverka[3] = "aba";
    char arr_text[3] = "abb";

    const int exp = 1;

    int result = errors_calc(dlina_text, arr_proverka, arr_text);

    ASSERT_EQUAL(exp, result);
}