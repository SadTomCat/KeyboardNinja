#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"
#include "include/struct_profile.h"

int main()
{
    system("clear");
    Profile *profile = sing_in();

    Profile *profile1 = malloc(sizeof(*profile1));
    profile1->name = "jija";
    profile1->levels_passed = 9;
    profile1->place_in_rating = 102;
    profile1->point = 322;
    profile1->interface = 1;

    intro(profile->interface);
    menu(profile, profile->interface);

    return 0;
}
