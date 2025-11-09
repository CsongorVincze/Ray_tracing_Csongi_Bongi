#ifndef HITTABLE_H
#define HITTABLE_H

#include <stdio.h>
#include <math.h>

#include "vec_3.h"
#include "color.h"
#include "ray.h"

typedef struct{
    point_3 p; // ebben taroljuk az eltalalt pontot
    vec_3 normal; // ebben taroljuk a normat
    double t; // mennyi "ido"-be telt a sugarnak eltalalni a pontot
} hit_rec;

typedef struct{ //? ezt lehet osszerakhatnam az elozo structal
    bool hit; // talalt-e? 
} hittable;





#endif