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

int start();
int action();
int train(Profile *profile, int intro_variant);
int action_secs();

int data;

#endif