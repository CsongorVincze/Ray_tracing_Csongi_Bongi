#ifndef HIT_LIST
#define HIT_LIST

#include "common_headers.h"
#include "hittable.h"
#include "sphere.h"

// ez a fuggveny igazabol arra jo hogy egy sugar menten vegigmegy az osszes gombon
// es megnezi h valamelyiket eltalalt-e a sugar
// ha igen: visszater igazzal es a fuggvenynek megadott (hit_rec tipusu) closest_hit-et
// beallitja a sugarral valo utkozesnek megfeleloen
// ha nem: visszater hamissal
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














#endif 
