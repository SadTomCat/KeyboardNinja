#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"
#include "include/scene.h"

int main()
{
    char* profile = add_profile();
    Profile profile1;
    profile1.name = "kirill";
    profile1.levels_passed = "2";
    profile1.place_in_rating = "1";
    profile1.point = "1337";

    int choice;
    intro();
    menu();

    return 0;
}