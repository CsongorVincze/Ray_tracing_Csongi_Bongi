#ifndef RAY_H
#define RAY_H

#include "vec_3.h"

typedef vec_3 point_3;

typedef struct{
    point_3 orig;
    vec_3 dir;
}ray_3;

point_3 _pos(ray_3 ray, double t);

#endif