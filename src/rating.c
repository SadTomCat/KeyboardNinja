#include <stdio.h>
#include <stdlib.h>
#include "include/rating.h"
#include "include/profile.h"

void add(Profile* profile, double time, double speed, int points)
{
    FILE *f = fopen("data/RATING.txt", "a+");

    fprintf(f, "%s %.2f %.0f %d\r\n", profile->name, time, speed, points);

    fclose(f);
}

void output()
{
    int i = 0;
    struct table t[10];

    FILE *f = fopen("data/RATING.txt", "r");

    system("clear");

    while (fscanf(f, "%s %lf %lf %d", t[i].name, &t[i].time, &t[i].speed, &t[i].points) != EOF) {
	printf("%d) %s %.2fsec %.0f character per minute %d points\n", i + 1, t[i].name, t[i].time, t[i].speed, t[i].points);
	i++;
    }
    fclose(f);
}

int point(double time, double speed)
{
    int point = (100-time/100)+(speed/10);

    return point;
}
