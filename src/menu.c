#include "include/menu.h"
#include "include/comp_mode.h"

int choosen_action()
{
    int choice = 0;
    printf("\nInput your choise: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        fast_intro();
        printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        printf("\nInput your choise: ");
    }

    return choice;
}

void fast_intro()
{
    int i, k;

    for (i = 0; i < 16; i++)
    {
        for (k = 0; k < 102; k++)
        {
            printf("%c", keyboard[i][k]);
        }
        printf("\n");
    }
}

void intro()
{
    system("clear");
    int i, j, k, t;
    int step;

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
}

int menu() //После выбора действия заново вызывается меню.
{
    int choice = 0;
    int a;
    int variants = 7;

    printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
    choice = choosen_action();
    while (choice < 0 || choice > 7)
    {
        system("clear");
        fast_intro();
        printf("\n\t1.Training    2.Scene    3.Competitive    4.Rating    5.Statistic    6.Help    7.Exit");
        choice = choosen_action();
    }

    if (choice == 1) //For training
    {
        //rating();
    }
    if (choice == 2) //Scene
    {
        //main();
    }
    if (choice == 3) //For competitive
    {
        comp_mode();
    }
    if (choice == 4) //For rating
    {
        //rating();
    }
    if (choice == 5) //For statistic
    {
        //statistic();
    }

    if (choice == 6)
    {
        system("clear");
        fast_intro();
        printf("\n|||Это игра для помощи начинающим ниндзя-программистаам, она должна помочь вам научиться быстро печатать.");
        printf("\n|||Для выбора действия введите число из представленного выбора\n");
        menu();
    }
    if (choice == 7)
    {
        exit(0);
    }
    menu();
}
