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


    sort();

    printf("\tTOP-10 Rating:\n\n\tNumber\tName\t\t\tTime\t\t\tSpeed\t\tPoints\n\n");

    while (fscanf(f, "%s %lf %lf %d", t[i].name, &t[i].time, &t[i].speed, &t[i].points) != EOF) {
	printf("\t%d)\t%s\t\t%.2f sec\t\t%.0f c/m\t\t%d\n\n", i + 1, t[i].name, t[i].time, t[i].speed, t[i].points);
	i++;

    }

    fclose(f);

    while (i != 0) {
	printf("Enter 0 to return to the menu: ");
	scanf("%d", &i);
	scanf("%*[^\n]");
    }

}

int point(double time, double speed)
{
    int point = (100-time/100)+(speed/10);

    return point;
}

void sort()
{
    struct table t[12];
    int i = 0, j, k;

    FILE *f = fopen("data/RATING.txt", "r");

    while (fscanf(f, "%s %lf %lf %d", t[i].name, &t[i].time, &t[i].speed, &t[i].points) != EOF) {
	i++;
    }
    fclose(f);

    for (j = 1; j < i; j++) {
	for (k = 0; k < i - j; k++) {
	    if (t[k].points < t[k+1].points) {
		t[12] = t[k];
		t[k] = t[k+1];
		t[k+1] = t[12];
	    }
	}
    }

    FILE *n = fopen("data/RATING.txt", "w");

    if (i >= 10) i = 10;

    for (k = 0; k < i; k++) {
	fprintf(n, "%s %f %f %d\r\n", t[k].name, t[k].time, t[k].speed, t[k].points);
    }
    fclose(n);
}
