#ifndef INTERVALS_H
#define INTERVALS_H

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    double min;
    double max;
}interval;

bool interval_contains(interval i, double x){
    if(i.min <= x && x <= i.max){
        return true;
    }
    return false;
}

bool interval_surrounds(interval i, double x){
    if(i.min < x && x < i.max){
        return true;
    }
    return false;
}

#define INTERVAL_UNIVERSE ((interval){.min = -INFINITY, .max = INFINITY }) //? remelem ezek mukodnek
#define INTERVAL_EMPTY ((interval){.min = INFINITY, .max = -INFINITY })







#endif 