#ifndef PROFILE_H_
#define PROFILE_H_

#include <stdio.h>
#include <inttypes.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"

//для каждого директивы учтен один символ для '\0', а еще в PROFILE учтены символы для пробелов  
#define NUM_CHAR_FOR_PROFILE 25 
#define NAME_SIZE 16   
#define NUM_POINT 5 
#define NUM_PLACE 2 

char* create_nickname(uint8_t fail_name);
char* verification_name(char* name);
char* add_profile();

typedef struct {
    char* name;
    char* levels_passed;
    char* point;
    char* place_in_rating;
} Profile;


#endif //PROFILE_H_