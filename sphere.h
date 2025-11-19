#ifndef SPHERE
#define SPHERE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "vec_3.h"
#include "ray.h"
#include "hittable.h"


typedef struct{
    point_3 center;
    double radius;
}sphere;

bool hit_sphere(sphere sp, ray_3 ray, double tmin, double tmax, hit_rec *hitdata){
    vec_3 oc = _add(sp.center, _neg(ray.orig));
    double a = _dot(ray.dir, ray.dir);
    double h = _dot(ray.dir, oc);
    double c = _dot(oc, oc) - sp.radius*sp.radius;
    double discriminant = h*h - a*c;
    if(discriminant < 0){
        return false;
    }
    
    double sqrtd = sqrt(discriminant);
    
    double root = (h - sqrtd)/a;
    if(root <= tmin || root >= tmax){
        root = (h + sqrtd)/a;
        if(root <= tmin || root >= tmax){
            return false;
        }
    }

    hitdata->p = _pos(ray, root);
    hitdata->outward_normal = _mul_s(1/sp.radius, _add(hitdata->p, _neg(sp.center)));
    hitdata->t = root;
    hit_side(hitdata, ray);// ezzel beallitjuk a hitdata normajat es h melyik oldalon vagyunk

    return true;
}

// gomboket csinalunk random parameterekkel
void _rand_spheres(int num_spheres, sphere* sp_array){ // ez itt egy tombot var
    srand(time(NULL));
    for(int i = 0; i < num_spheres; i++){
        double i_d = (double) i;
        sp_array[i].center.e[0] = -3.0 + i_d;               //((rand() % 10) + 5)/2;
        sp_array[i].center.e[1] = 0.0;              //((rand() % 10) + 5)/2;
        sp_array[i].center.e[2] = 5.0;             //((rand() % 10) + 5)/2;
        sp_array[i].radius =  1.0;              //((rand() % 10) + 5)/10;
    }
}
















#endif
