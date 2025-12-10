#ifndef ANIMATION_H
#define ANIMATION_H

#include "sphere.h"

void harm_osc_y(sphere sp_array[], int num_spheres, double amp, double omega, int t);
void random_walk(sphere sp_array[], int num_spheres);

#endif