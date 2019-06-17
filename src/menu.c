#include "include/menu.h"
#include "include/comp_mode.h"
#include "include/training.h"
#include "include/rating.h"

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

int choosen_action(int intro_variant)
{
    int choice = 0;

    printf("\nInput your choice: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        fast_intro(intro_variant);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Help    6.Exit");
        printf(KMAG9 "\nInput your choice: ");
    }

    return choice;
}

void fast_intro(int intro_variant)
{
    system("clear");
    int i, k;

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

void intro(int intro_variant)
{
    system("clear");
    int i, j, t;
    int step;

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

int menu(Profile *profile, int intro_variant) //После выбора действия заново вызывается меню.
{
    int choice = 0;

    system("clear");

    fast_intro(profile->interface);
    printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating     5.Help    6.Exit");
    choice = choosen_action(intro_variant);

    while (choice < 0 || choice > 6)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Competitive    4.Rating     5.Help    6.Exit");
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

    if (choice == 5)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n|||Это игра для помощи начинающим ниндзя-программистаам, она должна помочь вам научиться быстро печатать.");
        printf(KMAG9 "\n|||Для выбора действия введите число из представленного выбора");
        printf(KMAG9 "\n|||Пожалуйста, подождите\n");
        usleep(7000000);
    }

    if (choice == 6)
    {
        free(profile);
        exit(0);
    }

    menu(profile, profile->interface);

    return 0;
}
