#ifndef READ_AND_WRITE_H_
#define READ_AND_WRITE_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "menu.h"

#define MAX_TEXT_SIZE 431

char* read_from_file(char* file_name);
void write_text(char* text, uint16_t text_size);
void menu_equalization(uint8_t new_line, char* cur_menu);

#endif //READ_AND_WRITE_H_
