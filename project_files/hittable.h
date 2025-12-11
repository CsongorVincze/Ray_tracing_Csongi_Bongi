#ifndef HITTABLE_H
#define HITTABLE_H

#include <stdbool.h>
#include "vec_3.h"
#include "ray.h"

typedef struct{
    point_3 p; // ebben taroljuk az eltalalt pontot
    vec_3 outward_normal; // mindig kifele mutato norma
    vec_3 normal; // ez a norma mindig a sugarral elenkezo iranyba mutat
    double t; // mennyi "ido"-be telt a sugarnak eltalalni a pontot
    bool front_face; // kivulrol jon-e a sugar
} hit_rec;

void hit_side(hit_rec* blabla, ray_3 ray);

#endif