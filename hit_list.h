#ifndef HIT_LIST_H
#define HIT_LIST_H

#include "sphere.h"
#include "hittable.h"
#include "ray.h"
#include "intervals.h"
#include <stdbool.h>

bool which_hit(sphere* sp_array, int num_spheres, ray_3 ray, interval t_limits, hit_rec* closest_hit);

#endif 
