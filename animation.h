#ifndef ANIMATION_H
#define ANIMATION_H

#include "common_headers.h"
#include "sphere.h"
#include <time.h>



//oszcillacio az y tengely menten
void harm_osc_y( sphere sp_array[], int num_spheres, double amp, double omega, int t){
    for(int i = 1; i < num_spheres; i++){
        sp_array[i].center.e[1] += amp*sin(omega*t + (double)i);
    }
}

void random_walk( sphere sp_array[], int num_spheres){
    srand(time(NULL));
    for(int i = 1; i < num_spheres; i++){
        sp_array[i].center.e[0] += (double)((rand() % 11) - 5) / 100;
        sp_array[i].center.e[1] += (double)((rand() % 11) - 5) / 100;
        sp_array[i].center.e[2] += (double)((rand() % 11) - 5) / 100;
    }
}








#endif