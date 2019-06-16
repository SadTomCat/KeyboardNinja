#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"
#include "include/struct_profile.h"

int main()
{
    system("clear");
    //Profile *profile = add_profile();
    Profile *profile = sing_in();
    printf("%s", profile->name);
     
    Profile *profile1 = malloc(sizeof(*profile1));
    profile1->name = "jija_loh";
    profile1->levels_passed = 9;
    profile1->place_in_rating = 102;
    profile1->point = 322;
    profile1->interface = 1;

    //intro(profile1->interface);
    menu(profile1, profile1->interface);

    return 0;
}
