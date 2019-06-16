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

    //intro(profile1->interface);
    menu(profile, profile->interface);

    return 0;
}
