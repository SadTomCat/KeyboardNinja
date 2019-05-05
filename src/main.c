#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"
#include "include/struct_profile.h"

int main()
{
    char* profile = add_profile();

    Profile* profile1 = malloc(sizeof(*profile1));
    profile1->name = "jija_loh";
    profile1->levels_passed = 0;
    profile1->place_in_rating = 1;
    profile1->point = 1337;

    int choice;
    intro();
    menu(profile1);

    return 0;
}