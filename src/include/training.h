#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "struct_profile.h"

double wtime();

void start();
int action();
void train(Profile *profile, int intro_variant);
int action_secs();
double timeout(double time1, double time2);
int errors_calc(int dlina_text, char *arr_proverka, char *arr_text);

int data;

#endif