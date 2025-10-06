#ifndef RAY_H
#define RAY_H

#include "vec_3.h"

#include <stdio.h>
#include <math.h>

typedef vec_3 point_3;

point_3* position(point_3 origin, vec_3 direction, double t){ // ez meg itt egy nagyon basic sugarkoveto
    return _add(&origin, _mul(&t, &direction, 'd'));
}




#endif