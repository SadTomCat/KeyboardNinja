#include "../thirdparty/ctest.h"
#include "../src/include/training.h"
#include "../src/include/menu.h"

CTEST(time, timeout) //Ok
{
    double time1 = 3;
    double time2 = 6.5;

    double result1 = timeout(time1, time2);

    const double exp1 = 3.5;

    ASSERT_DBL_NEAR(exp1, result1);
}

CTEST(files, check_text) //Ok
{
    FILE *text;
    text = fopen("data/train_1.txt", "r");

    const int exp = 0;

    int result = check_text(text);

    ASSERT_DBL_NEAR(exp, result);
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
    printf("%d %d\n\n", result, profile->levels_passed);
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

    result = mistake_test(profile, 0, 2, 1, 1);
    exp_level = 0;
    exp_profile = 3;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
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

    result = mistake_test(profile, 0, 2, 6, 1);
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

    result = mistake_test(profile, 0, 0, 9, 1);
    exp_level = 0;
    exp_profile = 9;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    result = mistake_test(profile, 0, 0, 8, 1);
    exp_level = 0;
    exp_profile = 9;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}

CTEST(scene_easy, level_fail)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 0;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;

    result = mistake_test(profile, 3, 2, 1, 1);
    exp_level = 1;
    exp_profile = 0;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 1;
    result = mistake_test(profile, 4, 2, 2, 1);
    exp_level = 1;
    exp_profile = 1;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 2;
    result = mistake_test(profile, 10, 2, 3, 1);
    exp_level = 1;
    exp_profile = 2;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}

CTEST(scene_medium, level_fail)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 3;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;

    result = mistake_test(profile, 3, 1, 4, 1);
    exp_level = 1;
    exp_profile = 3;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 4;
    result = mistake_test(profile, 4, 1, 5, 1);
    exp_level = 1;
    exp_profile = 4;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 5;
    result = mistake_test(profile, 10, 1, 6, 1);
    exp_level = 1;
    exp_profile = 5;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}

CTEST(scene_insane, level_fail)
{
    uint8_t result, exp_level, exp_profile;
    Profile *profile = malloc(sizeof(*profile));
    profile->name = "jija_loh";
    profile->levels_passed = 6;
    profile->place_in_rating = 102;
    profile->point = 322;
    profile->interface = 2;

    result = mistake_test(profile, 3, 0, 7, 1);
    exp_level = 1;
    exp_profile = 6;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 7;
    result = mistake_test(profile, 4, 0, 8, 1);
    exp_level = 1;
    exp_profile = 7;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);

    profile->levels_passed = 8;
    result = mistake_test(profile, 10, 0, 9, 1);
    exp_level = 1;
    exp_profile = 8;
    ASSERT_EQUAL(exp_level, result);
    ASSERT_EQUAL(exp_profile, profile->levels_passed);
}
