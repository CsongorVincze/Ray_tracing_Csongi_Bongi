#include <stdio.h>
#include <math.h>

// itt csinalom meg a vec_3 "tipust"
#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    //double x, y, z;
    double e[3];
} vec_3;


//egysegvektor
vec_3 _zero(void); // csinal egy nullvektort
//muveleti fuggvenyek
vec_3* _add(vec_3* v, vec_3* w); //ket vektor osszeadasa
vec_3* _neg(vec_3* v); // vektor elemenkenti negalasa
vec_3* _mul_v(vec_3* v, vec_3* w); // elemenkenti szorzas vektorral
vec_3* _mul_s(double s, vec_3* w); // elemenkenti szorzas skalarral
vec_3* _rec(const vec_3* w); // elemenkenti reciprok szamitas
vec_3* _cross(vec_3* v, vec_3* w); // vektorialis szorzas
double _dot(vec_3* v, vec_3* w); // skalaris szorzas
double _length(vec_3* v); // vektor hossza
vec_3* _unit_vec(vec_3* v); //normalas
void _vec_print(vec_3 v); // kiirja a vektort




// fuggvenyek kifelytese

vec_3 _zero(void){ // ennek igazabol nincs nagyon ertelme
    vec_3 v = {0.0, 0.0, 0.0};
    return v;
}

vec_3* _neg(vec_3* v){ 
    static vec_3 NEG = {0, 0, 0};
    vec_3* u = &NEG;
        (*u).e[0] = -(*v).e[0];
        (*u).e[1] = -(*v).e[1];
        (*u).e[2] = -(*v).e[2];
    return u;
}

vec_3* _add(vec_3* v, vec_3* w){ // osszeadja a vektorokat helyben
    static vec_3 ADD = {0, 0, 0};
    vec_3* u = &ADD;
        (*u).e[0] = (*v).e[0] + (*w).e[0];
        (*u).e[1] = (*v).e[1] + (*w).e[1];
        (*u).e[2] = (*v).e[2] + (*w).e[2];
    return u;
}

vec_3* _mul_v(vec_3* v, vec_3* w){ // komponensenkenti szorzas v -> vektor
    static vec_3 MUL_V = {0, 0, 0};
    vec_3* u = &MUL_V;
        (*u).e[0] = (*w).e[0] * (*v).e[0];
        (*u).e[1] = (*w).e[1] * (*v).e[1];
        (*u).e[2] = (*w).e[2] * (*v).e[2];
    
    return u;
}

vec_3* _mul_s(double s, vec_3* w){ // komponensenkenti szorzas v -> vektor
    static vec_3 MUL_S = {0, 0, 0};
    vec_3* u = &MUL_S;
        (*u).e[0] = s*(*w).e[0];
        (*u).e[1] = s*(*w).e[1];
        (*u).e[2] = s*(*w).e[2];
    
    return u;
}


vec_3* _rec(const vec_3* w){
    static vec_3 REC = {0, 0, 0};
    vec_3* u = &REC;
        (*u).e[0] = 1/(*w).e[0];
        (*u).e[1] = 1/(*w).e[1];
        (*u).e[2] = 1/(*w).e[2];

    return u;
}

vec_3* _cross(vec_3* v, vec_3* w){
    static vec_3 CROSS = {0, 0, 0};
    vec_3* u = &CROSS;
        (*u).e[0] = (*v).e[1] * (*w).e[2] - (*v).e[2] * (*w).e[1];
        (*u).e[1] = (*v).e[2] * (*w).e[0] - (*v).e[0] * (*w).e[2];
        (*u).e[2] = (*v).e[0] * (*w).e[1] - (*v).e[1] * (*w).e[0];
    
    return u;
}

double _dot(vec_3* v, vec_3* w){
    return
        (*v).e[0] * (*w).e[0] +
        (*v).e[1] * (*w).e[1] +
        (*v).e[2] * (*w).e[2]; 
}

double _length(vec_3* v){
    return sqrt((*v).e[0] * (*v).e[0] + (*v).e[1] * (*v).e[1] + (*v).e[2] * (*v).e[2]);
}

vec_3* _unit_vec(vec_3* v){
    static vec_3 UNIT = {0, 0, 0};
    vec_3* u = &UNIT;
    double l = _length(v);
        (*u).e[0] = (*v).e[0] / l;
        (*u).e[1] = (*v).e[1] / l;
        (*u).e[2] = (*v).e[2] / l;
    return u;
}

void _vec_print(vec_3 v){
    printf("%.5f %.5f %.5f\n", v.e[0], v.e[1], v.e[2]);
}
#endif