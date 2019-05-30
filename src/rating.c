#include <stdio.h>
#include <stdlib.h>
#include "include/rating.h"
#include "include/profile.h"

void add(Profile* profile, double time, double speed)
{
    FILE *f = fopen("data/RATING.txt", "a+");

    fprintf(f, "%s %.2f %.0f\r\n", profile->name, time, speed);

    fclose(f);
}

void output()
{
    int i = 0;
    struct table t[10];

    FILE *f = fopen("data/RATING.txt", "r");

    system("clear");

    while (fscanf(f, "%s %lf %lf", t[i].name, &t[i].time, &t[i].speed) != EOF) {
	printf("%d) %s %.2fsec %.0f character per minute\n", i + 1, t[i].name, t[i].time, t[i].speed);
	i++;
    }
    fclose(f);
}
