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
    choice = menu();
    if (choice = 1) //Для training
    {               //Example
        //trainig();
    }
    if (choice = 2) //For main
    {
        scene(profile1);
    }
    if (choice = 3) //For competitive
    {
    }
    if (choice = 4) //For rating
    {
    }
    if (choice = 5) //For statistic
    {
    }

    return 0;
}