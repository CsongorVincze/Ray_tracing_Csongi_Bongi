// itt csinalom meg a vec_3 "tipust"

#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    double x, y, z;
} vec_3;

vec_3 vec_3_create(double x, double y, double z);
vec_3 vec_3_zero(void);
vec_3 vec_3_negate(vec_3 v);

#endif


// itt definialom a fuggvenyeket (constructor)
#include "vec_3.h"

vec_3 vec_3_create(double x, double y, double z){
    vec_3 v = {x, y, z};
    return v;
}

vec_3 vec_3_zero(void){
    vec_3 v = {0.0, 0.0, 0.0};
    return v;
}

vec_3 vec_3_negate(vec_3 v){ //itt ez nem mukodik
    vec_3 w = vec_3_create(-v.x, -v.y, -v.z);
    return w;
}

vec_3 vec_3_add(vec_3 v, vec_3 w){ // ez nagyon nem hatekony es masolatokat keszit
    vec_3 u = vec_3_create(v.x + w.x, v.y + w.y, v.z + w.z);
    return u;
}


// ez itt a main
#include "vec_3.h"
#include <stdio.h>
#include <math.h>
int main(){
    
vec_3 blabla = vec_3_create(1.0, 2.0, 3.0);
vec_3 bla = vec_3_negate(blabla);

printf("%.2f %.2f %.2f", bla.x, bla.y, bla.z);
    
    
    return 0;
}