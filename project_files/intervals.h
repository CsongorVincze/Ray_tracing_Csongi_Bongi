#ifndef INTERVALS_H
#define INTERVALS_H

#include <stdbool.h>
#include <math.h>

typedef struct{
    double min;
    double max;
}interval;

bool interval_contains(interval i, double x);
bool interval_surrounds(interval i, double x);

// Constants (macros for initialization)
// Note: INFINITY is in math.h
#define INTERVAL_UNIVERSE ((interval){.min = -INFINITY, .max = INFINITY }) 
#define INTERVAL_EMPTY ((interval){.min = INFINITY, .max = -INFINITY })

#endif 