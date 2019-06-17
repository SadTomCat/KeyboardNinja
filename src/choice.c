#include <stdio.h>
#include "include/choice.h"
#include "include/comp_mode.h"
#include <stdlib.h>
#include "include/menu.h"
#include "include/rating.h"

void choice_comp(Profile *profile)
{
	int number;

	printf("                                                              Your next step:\n\n");
	printf("                                            1) return to the menu           2) see rating\n\n");
	printf("                                            Your choice: ");
	scanf("%d", &number);
	scanf("%*[^\n]");

	if (number == 1)
	{
		system("clear");
		fast_intro(1);
		//menu();
	}
	else
	{
		if (number == 2)
		{
			output();
		}
		else
		{
			system("clear");
			printf("Error! Enter 1 or 2\n\n");
			choice_comp(profile);
		}
	}
}
