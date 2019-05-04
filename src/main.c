#include <stdio.h>
#include <unistd.h>
#include "include/menu.h"
#include "include/profile.h"

int main()
{
    char* profile = add_profile();

    int choice;
    intro();
    menu();
    

    return 0;
}