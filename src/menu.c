#include "include/menu.h"
#include "include/comp_mode.h"
#include "include/training.h"
#include "include/rating.h"

#define TEST 1

static char keyboard[16][102] = {
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"///KKK////KKK/EEEEEEEE/YYY///////YYY/BBBBBBBBB////OOOOOO/////////AAAA//////RRRRRRRRR///DDDDDD////////"},
    {"///KKK///KKK//EEEEEEEE//YYY/////YYY//BBB///BBB//OOO////OOO/////AAA//AAA////RRR/////RRR/DDD//DDD//////"},
    {"///KKK//KKK///EEE////////YYY///YYY///BBB///BBB//OOO////OOO///AAA//////AAA//RRR/////RRR/DDD////DDD////"},
    {"///KKK/KKK////EEE/////////YYY/YYY////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR/////RRR/DDD/////DDD///"},
    {"///KKKKKK/////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR////RRR//DDD/////DDD///"},
    {"///KKKKKK/////EEEEEEEE//////YYY//////BBB/BBBB//OOO//////OOO/AAAAAAAAAAAAAA/RRRRRRRRR///DDD/////DDD///"},
    {"///KKKKKK/////EEEEEEEE//////YYY//////BBB/BBBB//OOO//////OOO/AAAAAAAAAAAAAA/RRRRRRRRR///DDD/////DDD///"},
    {"///KKKKKK/////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR///RRR///DDD/////DDD///"},
    {"///KKK/KKK////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR////RRR//DDD/////DDD///"},
    {"///KKK//KKK///EEE///////////YYY//////BBB///BBB//OOO////OOO//AAA////////AAA/RRR/////RRR/DDD////DDD////"},
    {"///KKK///KKK//EEEEEEEE//////YYY//////BBB///BBB//OOO////OOO//AAA////////AAA/RRR/////RRR/DDD//DDD//////"},
    {"///KKK////KKK/EEEEEEEE//////YYY//////BBBBBBBBB////OOOOOO////AAA////////AAA/RRR/////RRR/DDDDDD////////"},
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"/////////////////////////////////////////////////////////////////////////////FROM NINJAS TO NINJAS///"},
};

static char keyboard2[16][102] = {
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"                                                                                                     "},
    {"  NNNN     NNN  IIIIII  NNNN     NNN      JJJJJJ       AAAA                                          "},
    {"  NNNNN    NNN  IIIIII  NNNNN    NNN      JJJJJJ     AAA  AAA       *                *       |       "},
    {"  NNN NN   NNN          NNN NN   NNN      JJJJJJ   AAA      AAA      **            **       |||      "},
    {"  NNN NN   NNN  IIIIII  NNN NN   NNN      JJJJJJ  AAA        AAA      ***        ***    *   |||   *  "},
    {"  NNN NN   NNN  IIIIII  NNN NN   NNN      JJJJJJ  AAA        AAA       ****    ****    *   |||||   * "},
    {"  NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAAAAAAAAAAAAA        **********       * ||||| *   "},
    {"  NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAAAAAAAAAAAAA         **    **        *********   "},
    {"  NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA        **********       **     **   "},
    {"  NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA       ****    ****      *********   "},
    {"  NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA      ***        ***     *********   "},
    {"  NNN   NN NNN  IIIIII  NNN   NN NNN     JJJJJJ   AAA        AAA     **            **    ***   ***   "},
    {"  NNN    NNNNN  IIIIII  NNN    NNNNN  JJJJJJ      AAA        AAA    *                *   ***   ***   "},
    {"                                                                                                     "},
    {"/////////////////////////////////////////////////////////////////////////////FROM NINJAS TO NINJAS///"},
};

int choosen_action(int intro_variant)
{
    int choice = 0;
#if (TEST == 1)
    choice = 2;
#endif
#if (TEST == 0)
    printf("\nInput your choice: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        fast_intro(intro_variant);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        printf(KMAG9 "\nInput your choice: ");
    }
#endif

    return choice;
}

void fast_intro(int intro_variant)
{
    system("clear");
    int i, k;
    if (intro_variant == 1)
    {
        for (i = 0; i < 16; i++)
        {
            for (k = 0; k < 102; k++)
            {
                printf(KMAG9 "%c", keyboard[i][k]);
            }
            printf("\n");
        }

        return;
    }

    if (intro_variant == 2)
    {
        for (i = 0; i < 16; i++)
        {
            for (k = 0; k < 102; k++)
            {
                printf(KMAG9 "%c", keyboard2[i][k]);
            }
            printf("\n");
        }

        return;
    }
}

void intro(int intro_variant)
{
    system("clear");
    int i, j, t;
    int step;

    if (intro_variant == 1)
    {
        j = 101;

        for (j = 101; j >= 0; j--)
        {                    //Шаг равен разнице числа элементов в строке +1 и числа элементов в строке
            system("clear"); //Шаг - количество выводимых символов строки
            step = 102 - j;  //В третьем форе печать строки, количество выводимых элементов равно шаг
                             //Выводится t элементов от k - t до k
            for (i = 0; i < 16; i++)
            {
                for (t = step; t > 0; t--)
                {
                    printf(KMAG9 "%c", keyboard[i][102 - t]);
                }
                printf("\n");
            }
            usleep(20000);
        }
    }
    else if (intro_variant == 2)
    {
        j = 101;

        for (j = 101; j >= 0; j--)
        {
            system("clear");
            step = 102 - j;

            for (i = 0; i < 16; i++)
            {
                for (t = step; t > 0; t--)
                {
                    printf(KMAG9 "%c", keyboard2[i][102 - t]);
                }
                printf("\n");
            }
            usleep(20000);
        }
    }
}

int menu(Profile *profile, int intro_variant) //После выбора действия заново вызывается меню.
{
    int choice = 0;

    system("clear");

    fast_intro(profile->interface);
    printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
    choice = choosen_action(intro_variant);
    while (choice < 0 || choice > 7)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        choice = choosen_action(profile->interface);
    }

    if (choice == 1) //For training
    {
        system("clear");
        train(profile, intro_variant);
    }
    if (choice == 2) //Scene
    {
        scene(profile);
    }
    if (choice == 3) //For competitive
    {
        system("clear");
        comp_mode(profile);
    }
    if (choice == 4) //For rating
    {
        output();
    }
    if (choice == 5) //For statistic
    {
        //statistic();
    }

    if (choice == 6)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n|||Это игра для помощи начинающим ниндзя-программистаам, она должна помочь вам научиться быстро печатать.");
        printf(KMAG9 "\n|||Для выбора действия введите число из представленного выбора");
        printf(KMAG9 "\n|||Пожалуйста, подождите\n");
        usleep(7000000);
    }

    if (choice == 7)
    {
        exit(0);
        free(profile);
    }

    menu(profile, profile->interface);

    return 0;
}
