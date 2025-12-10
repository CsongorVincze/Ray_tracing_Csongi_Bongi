#include "hittable.h"

void hit_side(hit_rec* blabla, ray_3 ray){
    if(_dot(ray.dir, blabla->outward_normal) > 0.0){
        blabla->front_face = false;
    }
    else{
        blabla->front_face = true;
    }
    blabla->normal = blabla->front_face ? blabla->outward_normal : _neg(blabla->outward_normal);

}
