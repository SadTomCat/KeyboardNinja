#ifndef SCENE_H_
#define SCENE_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include "curses.h"
#include "read.h"
#include "menu.h"
#include "struct_profile.h"

void scene(Profile* profile);
void easy(Profile* profile);
void medium(Profile* profile);
void insane(Profile* profile);
void play_level(Profile* profile, char* text, uint8_t max_mistake, long int max_time, uint8_t level_number);

#endif //SCENE_H_
