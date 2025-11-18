#ifndef SPHERE
#define SPHERE

#include <stdio.h>
#include <math.h>

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
    hitdata->normal = _mul_s(1/sp.radius, _add(hitdata->p, _neg(sp.center))); //!
    hitdata->t = root;



    return true;

}














#endif
