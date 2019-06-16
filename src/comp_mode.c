#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "include/comp_mode.h"
#include "include/choice.h"
#include "include/rating.h"

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int comp_mode(Profile* profile)
{

    int i = 0;

    while (i != 1) {
	system("clear");
	printf("\t\tYou are ready?\n\n\t\t1)Yes\t2)No\n\n\t\t");
	scanf("%d", &i);
	scanf("%*[^\n]");
	if (i == 2) return 0;
    }

    system("clear");

    srand(time(NULL));

    int length = 0, error = -1, number = rand() % 5 + 1;
    char ch, text[500], input[500];
    double speed;

    FILE *t;

    for (i = 3; i > 0; i--) {
	printf("\t\t%d\n\n", i);
	usleep(1000000);

    }
    system("clear");

    switch (number)
    {
    case 1:
        t = fopen("data/comp_1.txt", "r");
        break;
    case 2:
        t = fopen("data/comp_2.txt", "r");
        break;
    case 3:
        t = fopen("data/comp_3.txt", "r");
        break;
    case 4:
        t = fopen("data/comp_4.txt", "r");
        break;
    case 5:
        t = fopen("data/comp_5.txt", "r");
        break;
    }

    if (fgets(text, 500, t) != NULL)
    {
        puts(text);
        fclose(t);
    }
    printf("\n\n");

    length = strlen(text);

    double t1 = wtime();

    scanf("%*[^\n]");

    for (i = -1; i < length; i++) {
	ch = getchar();
	input[i] = ch;
	if (input[i] != text[i]) {
	    error++;
	}
    }

    scanf("%*[^\n]");

    printf("\n\n");

    double t2 = wtime();
    double t3 = (t2 - t1) + error;

    speed = length / t3 * 60;

    int points = point(t3, speed);

    printf("Your result:\n\n\tTime = %.2f sec\n\n\tNumber of errors = %d\n\n\tSpeed = %.0f characters per minute\n\n\t%d points\n\n", t3, error, speed, points);

    add(profile, t3, speed, points);

    choice_comp(profile);

    return 0;
}
