#include <stdio.h>
#include "include/rating.h"

void add(double time, double speed)
{
    char name[10];

    FILE *f = fopen("data/RATING.txt", "a+");

    printf("To save to the rating, enter Your name: ");
    scanf("%s", name);

    fprintf(f, "%s %.2f %.0f\r\n", name, time, speed);

    fclose(f);
}

void output()
{
    int i = 0;
    struct table t[10];

    FILE *f = fopen("data/RATING.txt", "r");

    while (fscanf(f, "%s %lf %lf", t[i].name, &t[i].time, &t[i].speed) != EOF) {
	printf("%d) %s %fsec %f character per minute", i + 1, t[i].name, t[i].time, t[i].speed);
	i++;
    }
    fclose(f);
}
