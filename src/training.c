#include "include/training.h"

void start()
{
    system("clear");
    printf("\n3\n");
    usleep(900000);
    printf("\n2\n");
    usleep(900000);
    printf("\n1\n");
    usleep(900000);
}

int errors_calc(int dlina_text, char *arr_proverka, char *arr_text)
{
    int i;
    int errors = 0;

    char bykva;

    for (i = -1; i < dlina_text; i++)
    {
        bykva = getchar();
        arr_proverka[i] = bykva;
        if (arr_proverka[i] != arr_text[i])
        {
            errors++;
        }
    }
    return errors - 1;
}

double timeout(double time1, double time2)
{
    double time = time2 - time1;
    if (time <= 0)
    {
        return 0;
    }
    return time;
}

int action()
{
    int choice = 0;

    printf("\nInput your choise: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        printf("\n             Make your choice\n1.Sentences  2.Words  3.Letters  4.Back");
        printf("\nInput your choise: ");
    }

    return choice;
}

int action_secs()
{
    int secs = 0;

    printf("\n\nInput time 5-99 (recommended 15-30)");

    while (scanf("%d", &secs) != 1)
    {
        scanf("%*[^\n]");

        system("clear");
        printf("\n\n\nInput time 5-99 (recommended 15-30)");
    }

    return secs;
}
int check_text(FILE *text)
{
    if (text == NULL)
    {
        printf("\nSorry, file can not be open");
        exit(0);
    }
    return 0;
}

void train(Profile *profile, int intro_variant)
{
    printf("\n             Make your choice\n1.Sentences  2.Words  3.Letters  4.Back");
    int choice = action();

    while (choice < 0 || choice > 4)
    {
        system("clear");
        printf("\n             Make your choice\n1.Sentences  2.Words  3.Letters  4.Back");
        choice = action();
    }

    int errors = 0, dlina_text = 0;
    char arr_text[100];
    char arr_proverka[100];
    int rezhim = 0;
    double time3 = 0;

    errors = 0;

    FILE *text;

    if (choice == 1)
    {
        rezhim = rand() % 2 + 1;
        switch (rezhim)
        {
        case 1:
            text = fopen("data/train_1.txt", "r");
            break;
        case 2:
            text = fopen("data/train_2.txt", "r");
            break;
        }
    }
    if (choice == 2)
    {
        rezhim = rand() % 2 + 1;
        switch (rezhim)
        {
        case 1:
            text = fopen("data/train_3.txt", "r");
            break;
        case 2:
            text = fopen("data/train_4.txt", "r");
            break;
        }
    }
    if (choice == 3)
    {
        rezhim = rand() % 2 + 1;
        switch (rezhim)
        {
        case 1:
            text = fopen("data/train_5.txt", "r");
            break;
        case 2:
            text = fopen("data/train_6.txt", "r");
            break;
        }
    }
    check_text(text);
    if (choice == 4)
    {
    }
    else
    {

        int secs = action_secs();
        while (secs < 5 || secs > 99)
        {
            system("clear");
            secs = action_secs();
        }

        start();
        double time1 = wtime();
        if (fgets(arr_text, 100, text) != NULL)
        {
            puts(arr_text);
            fclose(text);
        }

        printf("\n////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");

        dlina_text = strlen(arr_text);

        errors = errors_calc(dlina_text, arr_proverka, arr_text);
        scanf("%*[^\n]");

        double time2 = wtime();

        time3 = timeout(time1, time2);

        printf("Your errors = %d  Your time = %.2f", errors, time3);
        if (time3 < secs)
        {
            printf("\nTime mission completed");
        }
        else
        {
            printf("\nTime mission successfully failed");
        }
        if ((errors - 1 < 4) && (time3 < secs))
        {
            printf("\nCongratilations! You have a good result!");
        }

        printf("\n");
        usleep(8000000);
    }
}
