#include <stdio.h>
#include <math.h>

// itt csinalom meg a vec_3 "tipust"
#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    //double x, y, z;
    double e[3];
} vec_3;


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
    return sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
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
#endif