#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

double wtime();

int start();
int action();
int train();
int action_secs();

int data;

#endif