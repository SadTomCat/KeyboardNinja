#include <stdio.h>
#include "rating.h"
#include "user.h"

void add(double time, double speed)
{
    FILE *f = fopen("data/rating.txt", "a+");

    fprintf(f, "%s %.2f %.0f\r\n", name, time, speed);

    fclose(f);
}

void scan_t()
{
    int i;
    struct table t[10];

    FILE *f = fopen("data/rating.txt", "r");

    for (i = 0; i < 10; i++) {
	fscanf(f, "%s %lf %lf", t[i].name, &t[i].time, &t[i].speed);
    }
    fclose(f);
}
