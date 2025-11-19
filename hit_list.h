#ifndef HIT_LIST
#define HIT_LIST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "vec_3.h"
#include "ray.h"
#include "hittable.h"
#include "sphere.h"

// ez a fuggveny igazabol arra jo hogy egy sugar menten vegigmegy az osszes gombon
// es megnezi h valamelyiket eltalalt-e a sugar
// ha igen: visszater igazzal es a fuggvenynek megadott (hit_rec tipusu) closest_hit-et
// beallitja a sugarral valo utkozesnek megfeleloen
// ha nem: visszater hamissal
bool which_hit(sphere* sp_array, int num_spheres, ray_3 ray, double tmin, double tmax, hit_rec* closest_hit){
    hit_rec try_hit;
    double T = tmax;
    for(int i = 0; i < num_spheres; i++){
        if(hit_sphere(sp_array[i], ray, tmin, tmax, &try_hit)){
            try_hit.t < T;
            T = try_hit.t;
            *(closest_hit) = try_hit; //? remelem ez mukodik
        }
    }
    if(T != tmax){
        return true;
    }
    return false;
}



// todo: valahogy meg lehetne csinalni h lekerdezzuk egy altalanos objektum 
// todo: adattipusat es hozzacsatoljuk a megfelelo hit functiont, igy tobbfele
// todo: objektumot le tudunk renderelni














#endif 
