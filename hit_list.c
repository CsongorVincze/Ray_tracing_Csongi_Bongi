#include "hit_list.h"

bool which_hit(sphere* sp_array, int num_spheres, ray_3 ray, interval t_limits, hit_rec* closest_hit){
    hit_rec try_hit;
    double T = t_limits.max;
    for(int i = 0; i < num_spheres; i++){
        if(hit_sphere(sp_array[i], ray, t_limits, &try_hit)){
            if(try_hit.t < T){
                T = try_hit.t;
                *(closest_hit) = try_hit; //? remelem ez mukodik
            }
        }
    }
    if(T != t_limits.max){
        return true;
    }
    return false;
}
