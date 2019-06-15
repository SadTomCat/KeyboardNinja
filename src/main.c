#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"
#include "include/struct_profile.h"

int main()
{
    system("clear");
    Profile *profile = add_profile();

    Profile *profile1 = malloc(sizeof(*profile1));
    profile1->name = "jija_loh";
    profile1->levels_passed = 7;
    profile1->place_in_rating = 102;
    profile1->point = 322;
    profile1->interface = 2;

    intro(profile1->interface);
    menu(profile1, profile1->interface);

    free(profile);
    return 0;
}