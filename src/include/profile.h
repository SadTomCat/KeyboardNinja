#ifndef PROFILE_H_
#define PROFILE_H_

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "read_and_write.h"
#include "struct_profile.h"

#define NAME_SIZE 16 //учитывая '\0' т.е имя занимает 15 символов

/*Для Эдика!!!*/
/*15 + 1! + 1 + 1! + 1 + 1! + 4 + 1! + 1(1! == пробел, всего под профиль максимум 26 символов)*/
//ИМЯ_ПРОЙДЕНО.УРОВНЕЙ_МЕСТО.В.РЕЙТИНГЕ_КОЛ.ОЧКОВ_ИНТЕРФЕЙС (_ == пробел в файле)

char *create_nickname(uint8_t fail_name);
char *verification_name(char *name);
Profile *add_profile();
Profile *find_profile();
void write_profile(Profile *profile);
Profile *sing_in();

#endif //PROFILE_H_
