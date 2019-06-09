#include "include/training.h"

int start()
{
    system("clear");
    printf("\n3\n");
    usleep(900000);
    printf("\n2\n");
    usleep(900000);
    printf("\n1\n");
    usleep(900000);

    return 0;
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

int train(Profile *profile, int intro_variant)
{
    printf("\n             Make your choice\n1.Sentences  2.Words  3.Letters  4.Back");
    int choice = action();

    while (choice < 0 || choice > 4)
    {
        system("clear");
        printf("\n             Make your choice\n1.Sentences  2.Words  3.Letters  4.Back");
        choice = action();
    }

    int i, errors = 0, dlina_text = 0;
    char arr_text[100];
    char arr_proverka[100];
    char bykva;
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

        for (i = -1; i < dlina_text; i++)
        {
            bykva = getchar();
            arr_proverka[i] = bykva;
            if (arr_proverka[i] != arr_text[i])
            {
                errors++;
            }
        }
        scanf("%*[^\n]");
        double time2 = wtime();

        time3 = time2 - time1;

        printf("Your errors = %d  Your time = %.2f", errors - 1, time3);
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
        usleep(10000000);
    }

    return 0;
}
