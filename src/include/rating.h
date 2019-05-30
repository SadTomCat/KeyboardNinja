#ifndef RATING_H
#define RATING_H
#include "profile.h"
    struct table {
	int number;
	char name[10];
	double time;
	double speed;
    };

    void add(Profile* profile, double time, double speed);

//    void sort();

    void output();

#endif
