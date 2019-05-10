#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "include/comp_mode.h"
#include "include/choice.h"

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int comp_mode()
{
    srand(time(NULL));

    int i, length = 0, error = 0, number = rand() % 5 + 1;
    char ch, text[500], input[500];
    double speed;

    FILE *t;

    for (i = 3; i > 0; i--) {
	printf("%d\n\n", i);
	usleep(1000000);
    }
    system("clear");

    switch(number) {
	case 1:
	   t = fopen("data/1.txt", "r");
	    break;
	case 2:
	    t = fopen("data/2.txt", "r");
	    break;
	case 3:
	    t = fopen("data/3.txt", "r");
	    break;
	case 4:
	    t = fopen("data/4.txt", "r");
	    break;
	case 5:
	    t = fopen("data/5.txt", "r");
	    break;
    }

    if (fgets(text, 500, t) != NULL) {
	puts(text);
        fclose(t);
    }
    printf("\n\n");

    length = strlen(text);

    double t1 = wtime();

    for (i = 0; i < length; i++) {
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

    printf("Your result:\n\nTime = %.2f sec\n\nNumber of errors = %d\n\nSpeed = %.0f characters per minute\n\n", t3, error, speed);

    choice();

    return 0;
}
