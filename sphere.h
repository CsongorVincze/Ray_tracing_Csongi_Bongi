#ifndef SPHERE
#define SPHERE


#include "common_headers.h"
#include "hittable.h"
#include <time.h>


typedef struct{
    point_3 center;
    double radius;
}sphere;

bool hit_sphere(sphere sp, ray_3 ray, interval t_limits, hit_rec *hitdata){
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
    if(!interval_surrounds(t_limits, root)){
        root = (h + sqrtd)/a;
        if(!interval_surrounds(t_limits, root)){
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
void _array_spheres(int num_spheres, sphere* sp_array){ // ez itt egy tombot var
    srand(time(NULL));
    for(int i = 0; i < num_spheres; i++){
        double i_d = (double) i;
        sp_array[i].center.e[0] = -3.0 + i_d;
        sp_array[i].center.e[1] = 0.0;
        sp_array[i].center.e[2] = 5.0;
        sp_array[i].radius =  1.0;
    }
}

void _rand_spheres(int num_spheres, sphere* sp_array){ // ez itt egy tombot var
    srand(time(NULL));
    for(int i = 1; i < num_spheres; i++){
        double i_d = (double) i;
        sp_array[i].center.e[0] = (double)((rand() % 10) - 5)/2;
        sp_array[i].center.e[1] = (double)((rand() % 10) + 5)/10;
        sp_array[i].center.e[2] = (double)((rand() % 10) + 10)/2;
        sp_array[i].radius = (double)((rand() % 10) + 5)/15;

        // printf("\nsp_array[%d].center.e[0]: %lf\n", i, sp_array[i].center.e[0]);
        // printf("sp_array[%d].center.e[1]: %lf\n", i, sp_array[i].center.e[1]);  
        // printf("sp_array[%d].center.e[2]: %lf\n", i, sp_array[i].center.e[2]);  
        // printf("sp_array[%d].radius: %lf\n", i, sp_array[i].radius);            
    }
}
















#endif
