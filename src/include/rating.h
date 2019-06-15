#ifndef RATING_H
#define RATING_H
#include "profile.h"

    struct table {
	int number;
	char name[16];
	double time;
	double speed;
	int points;
    };

    void add(Profile* profile, double time, double speed, int points);

    void sort();

    void output();

    int point(double time, double speed);

#endif
