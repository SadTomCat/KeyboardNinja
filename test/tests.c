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

CTEST(scene_easy, level_pass)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 0;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;

    //0 mistake
    result = mistake_test(profile, 0, 2, 1, 1);
    exp_level = 0;
    exp_profile = 1;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 2, 2, 1);
    exp_level = 0;
    exp_profile = 2;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 2, 3, 1);
    exp_level = 0;
    exp_profile = 3;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);


    //1 mistake
    profile->levels_passed = 0;

    result = mistake_test(profile, 1, 2, 1, 1);
    exp_level = 0;
    exp_profile = 1;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 1, 2, 2, 1);
    exp_level = 0;
    exp_profile = 2;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 1, 2, 3, 1);
    exp_level = 0;
    exp_profile = 3;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    //2 mistake
    profile->levels_passed = 0;

    result = mistake_test(profile, 2, 2, 1, 1);
    exp_level = 0;
    exp_profile = 1;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 2, 2, 2, 1);
    exp_level = 0;
    exp_profile = 2;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 2, 2, 3, 1);
    exp_level = 0;
    exp_profile = 3;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

/*
    //2 mistake
    profile->levels_passed = 0;

    result = mistake_test(profile, 3, 2, 1, 1);
    exp_level = 1;
    exp_profile = 0;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 3, 2, 2, 1);
    exp_level = 1;
    exp_profile = 0;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 3, 2, 3, 1);
    exp_level = 1;
    exp_profile = 0;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
*/
}

CTEST(scene_medium, level_pass)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 3;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;

    //0 mistake
    result = mistake_test(profile, 0, 1, 4, 1);
    exp_level = 0;
    exp_profile = 4;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 1, 5, 1);
    exp_level = 0;
    exp_profile = 5;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 1, 6, 1);
    exp_level = 0;
    exp_profile = 6;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    //1 mistake
    profile->levels_passed = 3;
    result = mistake_test(profile, 1, 1, 4, 1);
    exp_level = 0;
    exp_profile = 4;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 1, 1, 5, 1);
    exp_level = 0;
    exp_profile = 5;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 1, 1, 6, 1);
    exp_level = 0;
    exp_profile = 6;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}


CTEST(scene_insane, level_pass)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 6;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;


    result = mistake_test(profile, 0, 0, 7, 1);
    exp_level = 0;
    exp_profile = 7;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 0, 8, 1);
    exp_level = 0;
    exp_profile = 8;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
    
    result = mistake_test(profile, 0, 0, 9, 1);
    exp_level = 0;
    exp_profile = 9;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}
