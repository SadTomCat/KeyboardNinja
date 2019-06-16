#include "include/read_and_write.h"

char *read_from_file(char *file_name)
{
    FILE *file;
    char *text = malloc(sizeof(char) * MAX_TEXT_SIZE);

    if (text == NULL)
    {
        printf("ERROR: no memory has been allocated\n");
        exit(1);
    }

    if ((file = fopen(file_name, "r")) == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

    while (fgets(text, MAX_TEXT_SIZE, file))
        ;

    fclose(file);

    return text;
}

void print_text(char *text, uint16_t text_size)
{
    char *word = malloc(sizeof(char) * 30);
    int i = 0, j = 0, len = 0;

    printf("\n");
    while (i < text_size)
    {
        while (text[i] != ' ' && i < text_size)
        {
            word[j] = text[i];
            len++;
            j++;
            i++;
        }

        len++;
        word[j] = '\0';
        j = 0;
        i++;

        if (len <= 101)
        {
            printf(KMAG9 "%s ", word);
        }
        else
        {
            printf(KMAG9 "\n%s ", word);
            len = strlen(word) + 1;
        }
    }

    printf("\n\n");
    printf(KMAG4 "/////////////////////////////////////////////////////////////////////////////////////////////////////");
    printf(KMAG9 "\n\n");
    free(word);
}

void menu_equalization(uint8_t new_line, char *cur_menu)
{
    uint8_t num_space = (101 - strlen(cur_menu)) / 2;

    for (uint8_t i = 0; i < new_line; i++)
    {
        printf("\n");
    }

    for (uint8_t i = 0; i < num_space; i++)
    {
        printf(" ");
    }

    printf("%s\n", cur_menu);
}

void print_mistake_text(char *correct, char *incorrect, uint16_t text_size)
{
    char word1[30];
    char word2[30];
    uint16_t i = 0, j = 0, len = 0, k;

    while (i < text_size)
    {
        while (incorrect[i] != ' ' && i < text_size)
        {
            word1[j] = incorrect[i];
            word2[j] = correct[i];
            len++;
            j++;
            i++;
        }

        len++;
        word1[j] = '\0';
        word2[j] = '\0';

        if (len <= 101)
        {
            for (k = 0; k <= j; k++)
            {
                if (word1[k] == word2[k])
                {
                    printf(KMAG9 "%c", word1[k]);
                }
                else
                {
                    printf(KMAG1 "%c", word1[k]);
                }
            }

            printf(" ");
        }
        else
        {
            printf("\n");
            len = strlen(word1) + 1;
            for (k = 0; k < j; k++)
            {
                if (word1[k] == word2[k])
                {
                    printf(KMAG9 "%c", word1[k]);
                }
                else
                {
                    printf(KMAG1 "%c", word1[k]);
                }
            }

            printf(" ");
        }

        i++;
        j = 0;
    }
    printf(KMAG4 "\n\n/////////////////////////////////////////////////////////////////////////////////////////////////////");
    printf("\n\nPut '1' for continue: ");
    while (getchar() != '1')
        ;
}