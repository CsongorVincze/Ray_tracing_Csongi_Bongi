#ifndef RENDER_H
#define RENDER_H

#include "vec_3.h"
#include "ray.h"
#include "sphere.h"
#include "hittable.h"
#include "color.h"
#include <stdio.h>

void viewport_creator(int image_width, int* image_height, double aspect_ratio, double focal_length, double viewport_height, double* viewport_width, point_3 camera_center, vec_3* viewport_h, vec_3* viewport_v, vec_3* delta_h, vec_3* delta_v, point_3* upper_left, point_3* kezdo_pix);

color ray_color(sphere sp_array[], int num_spheres, ray_3 ray, hit_rec *hitdata, double reflection_number, int depth);

vec_3 rand_square();

void render(int image_width, int image_height, point_3 camera_center, vec_3 delta_h, vec_3 delta_v, point_3 kezdo_pix, sphere sp_array[], int num_spheres, double reflection_number, FILE* fp);

#endif