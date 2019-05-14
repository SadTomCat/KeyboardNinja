#include "include/menu.h"
#include "include/comp_mode.h"
#include "include/training.h"
#include "include/rating.h"

int choosen_action(int intro_variant)
{
    int choice = 0;
    printf("\nInput your choice: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        fast_intro(intro_variant);
        printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        printf("\nInput your choice: ");
    }

    return choice;
}

void fast_intro(int intro_variant)
{
    int i, k;
    if (intro_variant == 1)
    {
        for (i = 0; i < 16; i++)
        {
            for (k = 0; k < 102; k++)
            {
                printf("%c", keyboard[i][k]);
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
                printf("%c", keyboard2[i][k]);
            }
            printf("\n");
        }

        return;
    }
    
    
}

void intro(int intro_variant)
{
    
    system("clear");
    int i, j, k, t;
    int step;
    if (intro_variant == 1){  
    j = 101;
    k = 102;

    for (j = 101; j >= 0; j--)
    {                    //Шаг равен разнице числа элементов в строке +1 и числа элементов в строке
        system("clear"); //Шаг - количество выводимых символов строки
        step = k - j;

        for (i = 0; i < 16; i++)
        { //В третьем форе печать строки, количество выводимых элементов равно шаг
            for (t = step; t > 0; t--)
            { //Выводится t элементов от k - t до k
                printf("%c", keyboard[i][k - t]);
            }
            printf("\n");
        }
        usleep(20000);
    }
    } else
    {
        system("clear");
        step = k - j;

        for (i = 0; i < 16; i++)
        { 
            for (t = step; t > 0; t--)
            { 
                printf("%c", keyboard2[i][k - t]);
            }
            printf("\n");
        }
        usleep(20000);
    }
}

int menu(Profile* profile, int intro_variant) //После выбора действия заново вызывается меню.
{
    int choice = 0;
    int a;
    int variants = 7;

    system("clear");

    fast_intro(intro_variant);
    printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
    choice = choosen_action(intro_variant);
    while (choice < 0 || choice > 7)
    {
        system("clear");
        fast_intro(intro_variant);
        printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        choice = choosen_action(intro_variant);
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
        comp_mode();
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
        fast_intro(intro_variant);
        printf("\n|||Это игра для помощи начинающим ниндзя-программистаам, она должна помочь вам научиться быстро печатать.");
        printf("\n|||Для выбора действия введите число из представленного выбора\n");
        usleep(7000000);
    }

    if (choice == 7)
    {
        exit(0);
    }

    menu(profile, intro_variant);
}

