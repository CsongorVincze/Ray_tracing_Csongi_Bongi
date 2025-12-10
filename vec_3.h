#include <stdio.h>
#include <math.h>
#include <time.h>

// itt csinalom meg a vec_3 "tipust"
#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    //double x, y, z;
    double e[3];
} vec_3;

//todo: itt meg kommentelni kell
//krealo fuggvenzek
vec_3 _element(double s); // vektort csinal ugyan olyan elemekbol
vec_3 _create(double x, double y, double z);

//muveleti fuggvenyek
vec_3 _add(vec_3 v, vec_3 w); //ket vektor osszeadasa
vec_3 _neg(vec_3 v); // vektor elemenkenti negalasa
vec_3 _mul_v(vec_3 v, vec_3 w); // elemenkenti szorzas vektorral
vec_3 _mul_s(double s, vec_3 w); // elemenkenti szorzas skalarral
vec_3 _rec(const vec_3 w); // elemenkenti reciprok szamitas
vec_3 _cross(vec_3 v, vec_3 w); // vektorialis szorzas
double _dot(vec_3 v, vec_3 w); // skalaris szorzas
double _length(vec_3 v); // vektor hossza
vec_3 _unit_vec(vec_3 v); //normalas
void _vec_print(vec_3 v); // kiirja a vektort




// fuggvenyek kifelytese

vec_3 _element(double s){ // egyseges elemekkel feltolti a vektort
    vec_3 u;
    u.e[0] = s;
    u.e[1] = s;
    u.e[2] = s;
    return u;
}

vec_3 _create(double x, double y, double z){ // kreal egy vektort
    vec_3 u;
        u.e[0] = x;
        u.e[1] = y;
        u.e[2] = z;
    return u;
}

vec_3 _neg(vec_3 v){ 
    vec_3 u;
        u.e[0] = -v.e[0];
        u.e[1] = -v.e[1];
        u.e[2] = -v.e[2];
    return u;
}

vec_3 _add(vec_3 v, vec_3 w){ // osszeadja a vektorokat
    vec_3 u;
        u.e[0] = v.e[0] + w.e[0];
        u.e[1] = v.e[1] + w.e[1];
        u.e[2] = v.e[2] + w.e[2];
    return u;
}

vec_3 _mul_v(vec_3 v, vec_3 w){ // komponensenkenti szorzas v -> vektor
    vec_3 u;
        u.e[0] = w.e[0] * v.e[0];
        u.e[1] = w.e[1] * v.e[1];
        u.e[2] = w.e[2] * v.e[2];
    
    return u;
}

vec_3 _mul_s(double s, vec_3 w){ // komponensenkenti szorzas v -> vektor
    vec_3 u;
        u.e[0] = s*w.e[0];
        u.e[1] = s*w.e[1];
        u.e[2] = s*w.e[2];
    
    return u;
}


vec_3 _rec(const vec_3 w){
    vec_3 u;
        u.e[0] = 1/w.e[0];
        u.e[1] = 1/w.e[1];
        u.e[2] = 1/w.e[2];

    return u;
}

vec_3 _cross(vec_3 v, vec_3 w){
    vec_3 u;
        u.e[0] = v.e[1] * w.e[2] - v.e[2] * w.e[1];
        u.e[1] = v.e[2] * w.e[0] - v.e[0] * w.e[2];
        u.e[2] = v.e[0] * w.e[1] - v.e[1] * w.e[0];
    
    return u;
}

double _dot(vec_3 v, vec_3 w){
    return
        v.e[0] * w.e[0] +
        v.e[1] * w.e[1] +
        v.e[2] * w.e[2]; 
}

double _length(vec_3 v){
    return sqrt(_dot(v, v));
}

vec_3 _unit_vec(vec_3 v){
    vec_3 u;
    double l = _length(v);
        u.e[0] = v.e[0] / l;
        u.e[1] = v.e[1] / l;
        u.e[2] = v.e[2] / l;
    return u;
}

void _vec_print(vec_3 v){
    printf("%.5f %.5f %.5f\n", v.e[0], v.e[1], v.e[2]);
}

// 0 es 1 kozott kaunk egy random szamot
static inline double rand_01(){
    return (double)rand() / ((double)RAND_MAX + 1.0);
}

static inline double rand_mm(double min, double max){
    return min + (max - min) * rand_01();
}

vec_3 _rand_vec_01(){
    return _create(rand_01(), rand_01(), rand_01());
}

vec_3 _rand_vec_mm(double min, double max){ //? ugyan olyan neven hivom oket
    return _create(rand_mm(min, max), rand_mm(min, max), rand_mm(min, max));
}

// ez egy random iranyu egysegvektor
vec_3 _rand_unit_vec(){
    while(true){
        vec_3 v = _rand_vec_01();
        if(1e-100 < _dot(v,v) && _dot(v, v) <= 1){
            return _unit_vec(v);
        }
    }
}

// visszaadjunk egy olyan random vektort ami a gomb "kulso oldalan" van
vec_3 _unit_vec_on_hemisphere(vec_3 normal){
    vec_3 u = _rand_unit_vec();
    if(_dot(normal, u) > 0){
        return u;
    }
    else{
        return _neg(u);
    }
}

#endif