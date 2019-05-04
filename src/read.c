#include "include/read.h"

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