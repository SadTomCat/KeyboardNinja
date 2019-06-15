#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct_profile.h"
#include "scene.h"

#define KMAG1 "\x1B[31m" //красный
#define KMAG2 "\x1B[32m" //зеленый
#define KMAG3 "\x1B[33m" //убогий
#define KMAG4 "\x1B[34m" //синий
#define KMAG5 "\x1B[35m" //фиолетовый
#define KMAG6 "\x1B[36m" //голубой
#define KMAG9 "\x1B[39m" //белый

int choosen_action();
void intro(int intro_variant);
void fast_intro(int intro_variant);
int menu(Profile *profile, int intro_variant);

#endif //MENU_H_