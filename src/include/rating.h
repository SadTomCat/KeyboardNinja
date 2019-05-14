#ifndef RATING_H
#define RATING_H

    struct table {
	int number;
	char name[10];
	double time;
	double speed;
    };

    void add(double time, double speed);

//    void sort();

    void output();

#endif
