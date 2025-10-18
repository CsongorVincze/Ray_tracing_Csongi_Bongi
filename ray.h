#ifndef RAY_H
#define RAY_H

#include "vec_3.h"

#include <stdio.h>
#include <math.h>

typedef vec_3 point_3;

point_3* position(point_3 origin, vec_3 direction, double t){ // ez meg itt egy nagyon basic sugarkoveto    
    static point_3 POS = {0, 0, 0};
    point_3* u = &POS;
    u = _add(&origin, _mul_s(t, &direction));
    return u;
}




#endif