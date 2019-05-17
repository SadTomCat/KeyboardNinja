#include "include/read_and_write.h"

char* read_from_file(char* file_name)
{
    FILE* file;
    char* text = malloc(sizeof(char) * MAX_TEXT_SIZE);

    if (text == NULL) {
        printf("ERROR: no memory has been allocated\n");
        exit(1);
    }
    
    if ((file = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while (fgets(text, MAX_TEXT_SIZE, file));
    
    fclose(file);

    return text;
}

void write_text(char* text, uint16_t text_size)
{
    char word[30];
    int i = 0, j = 0, len = 0;

    printf("\n");
    while (i < text_size) {
        while (text[i] != ' ' && i < text_size) {
            word[j] = text[i];
            len++;
            j++;
            i++;
        }

        len++;        
        word[j] = '\0'; 
        j = 0;
        i++;

        if (len <= 101) {
            printf(KMAG9 "%s ", word);    
        } else {
            printf(KMAG9 "\n%s ", word);
            len = strlen(word) + 1;
        }
    }

    printf("\n\n");
    printf(KMAG4 "/////////////////////////////////////////////////////////////////////////////////////////////////////");    
    printf(KMAG9 "\n\n");
}

void menu_equalization(uint8_t new_line, char* cur_menu) {
    uint8_t num_space = (101 - strlen(cur_menu)) / 2;

    for (uint8_t i = 0; i < new_line; i++) {
        printf("\n");
    }

    for (uint8_t i = 0; i < num_space; i++) {
        printf(" ");
    }

    printf("%s\n", cur_menu);
}