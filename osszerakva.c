// itt csinalom meg a vec_3 "tipust"

#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    //double x, y, z;
    double e[3];
} vec_3;

//krealo fuggvenyek
vec_3 _create(double x, double y, double z);
vec_3 _zero(void);
//muveleti fuggvenyek
vec_3* _neg(vec_3* v);
vec_3* _add(vec_3* v, const vec_3* w);
vec_3* _mul(vec_3* v, const vec_3* w);
vec_3* _div(vec_3* v, const vec_3* w);

#endif

// fuggvenyek kifelytese
#include "vec_3.h"

vec_3 _create(double x, double y, double z){
    //vec_3 v = {x, y, z};
    vec_3 v = {x, y, z};
    return v;
}

vec_3 _zero(void){
    vec_3 v = {0.0, 0.0, 0.0};
    return v;
}

vec_3* _neg(vec_3* v){ //itt ez nem mukodik
    (*v).e[0] = -(*v).e[0];
    (*v).e[1] = -(*v).e[1];
    (*v).e[2] = -(*v).e[2];
    return v;
}

vec_3* _add(vec_3* v, const vec_3* w){ // osszeadja a vektorokat helyben
    (*v).e[0] += (*w).e[0];
    (*v).e[1] += (*w).e[1];
    (*v).e[2] += (*w).e[2];
    return v;
}


// ez itt a main
#include "vec_3.h"
#include <stdio.h>
#include <math.h>
int main(){
    

vec_3 blabla = _create(1.0, 2.0, 3.0);
vec_3 nana = _create(5.0, 6.0, 7.0);


_add(_neg(&blabla), &nana);


printf("%.2f %.2f %.2f\n", blabla.e[0], blabla.e[1], blabla.e[2]);
    
    return 0;
}