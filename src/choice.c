#include <stdio.h>
#include "include/choice.h"
#include "include/comp_mode.h"
#include <stdlib.h>
#include "include/menu.h"

void choice()
{
    int number;

    printf("Your next step:\n1) restart\n2) return to the menu\n\nYour choice: ");
    scanf("%d", &number);
    scanf("%*[^\n]");

    if (number == 1) {
	comp_mode();
    } else {
	if (number == 2) {
	    system("clear");
	    fast_intro(1);
	    //menu();
	} else {
	    system("clear");
	    printf("Error! Enter 1 or 2\n\n");
	    choice();
	}
   }
}
