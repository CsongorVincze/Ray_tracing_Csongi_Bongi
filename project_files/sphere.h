#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec_3.h"
#include "ray.h"
#include "intervals.h"

typedef struct{
    point_3 center;
    double radius;
}sphere;

bool hit_sphere(sphere sp, ray_3 ray, interval t_limits, hit_rec *hitdata);
void _array_spheres(int num_spheres, sphere* sp_array);
void _rand_spheres(int num_spheres, sphere* sp_array);

#endif
