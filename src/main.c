#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"
#include "include/struct_profile.h"

int main()
{
    system("clear");
    Profile* profile = add_profile();
    int intro_variant = 1;
    printf("%s %d %d %d %d", profile->name, profile->levels_passed, profile->place_in_rating, profile->point, profile->interface);
/*
    Profile* profile1 = malloc(sizeof(*profile1));
    profile1->name = "jija_loh";
    profile1->levels_passed = 8;
    profile1->place_in_rating = 102;
    profile1->point = 322;

    int choice;
    intro(intro_variant);
    menu(profile1, intro_variant);
*/
    return 0;
}