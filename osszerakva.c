#include <stdio.h>
#include <math.h>

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
vec_3* _mul(void* v, vec_3* w, const char type);
vec_3* _rec(vec_3* v, const vec_3* w);
vec_3 _cross(vec_3* v, vec_3* w);
double _dot(vec_3* v, vec_3* w);
double _length(vec_3* v);
vec_3* _unit_vec(vec_3* v);


#endif


// fuggvenyek kifelytese

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

vec_3* _mul(void* v, vec_3* w, const char type){ // komponensenkenti szorzas v -> vektor
    if(type == 'v'){
        vec_3 v_ = *(vec_3*)v;
        (*w).e[0] *= v_.e[0];
        (*w).e[1] *= v_.e[1];
        (*w).e[2] *= v_.e[2];
    }
    else{
        double v_ = *(double*)v;
        (*w).e[0] *= v_;
        (*w).e[1] *= v_;
        (*w).e[2] *= v_;
    }
    return w;
}

vec_3 _cross(vec_3* v, vec_3* w){
    vec_3 u = {
        (*v).e[1] + (*w).e[2] - (*v).e[2] + (*w).e[1],
        (*v).e[2] + (*w).e[0] - (*v).e[0] + (*w).e[2],
        (*v).e[0] + (*w).e[1] - (*v).e[1] + (*w).e[0]
    };
    return u;
}

double _dot(vec_3* v, vec_3* w){
    return
        (*v).e[0] * (*v).e[0] +
        (*v).e[1] * (*v).e[1] +
        (*v).e[2] * (*v).e[2]; 
}

double _length(vec_3* v){
    return sqrt((*v).e[0] * (*v).e[0] + (*v).e[1] * (*v).e[1] + (*v).e[2] * (*v).e[2]);
}

vec_3* _unit_vec(vec_3* v){
    double l = _length(v);
    (*v).e[0] /= l;
    (*v).e[0] /= l;
    (*v).e[0] /= l;
    return v;
}

void _vec_print(vec_3 v){
    printf("%.2f %.2f %.2f\n", v.e[0], v.e[1], v.e[2]);
}


// ez itt a main
int main(){
        

    vec_3 blabla = {1.0, 2.0, 3.0};
    vec_3 nana = {5.0, 6.0, 7.0};
    vec_3 z = _zero();

    double l = _length(&blabla);
    printf("%f\n", l);

    vec_3 c = _cross(&blabla, &nana);

    _vec_print(c);


return 0;
}