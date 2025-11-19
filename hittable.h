#ifndef HITTABLE_H
#define HITTABLE_H

#include "common_headers.h"

typedef struct{
    point_3 p; // ebben taroljuk az eltalalt pontot
    vec_3 outward_normal; // mindig kifele mutato norma
    vec_3 normal; // ez a norma mindig a sugarral elenkezo iranyba mutat
    double t; // mennyi "ido"-be telt a sugarnak eltalalni a pontot
    bool front_face; // kivulrol jon-e a sugar
} hit_rec;

void hit_side(hit_rec* blabla, ray_3 ray){
    if(_dot(ray.dir, blabla->outward_normal) > 0.0){
        blabla->front_face = false;
    }
    else{
        blabla->front_face = true;
    }
    blabla->normal = blabla->front_face ? blabla->outward_normal : _neg(blabla->outward_normal);

}



typedef struct{ //? ezt lehet osszerakhatnam az elozo structal
    bool hit; // talalt-e? 
} hittable;





#endif