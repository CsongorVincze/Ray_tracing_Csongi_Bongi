#ifndef RAY_H
#define RAY_H

#include "vec_3.h"

#include <stdio.h>
#include <math.h>

typedef vec_3 point_3;

typedef struct{
    point_3 orig;
    vec_3 dir;
}ray_3;

point_3 _pos(ray_3 ray, double t){ // ez itt egy basic sugarkoveto    
    vec_3 u;
    u = _add(ray.orig, _mul_s(t, ray.dir));
    return u;
}





#endif