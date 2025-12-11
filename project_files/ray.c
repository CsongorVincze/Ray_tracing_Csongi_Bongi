#include "ray.h"

point_3 _pos(ray_3 ray, double t){ // ez itt egy basic sugarkoveto    
    vec_3 u;
    u = _add(ray.orig, _mul_s(t, ray.dir));
    return u;
}
