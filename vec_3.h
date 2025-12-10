#ifndef VEC_3_H
#define VEC_3_H

// itt csinalom meg a vec_3 "tipust"
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


// Random functions
double rand_01();
double rand_mm(double min, double max);
vec_3 _rand_vec_01();
vec_3 _rand_vec_mm(double min, double max);
vec_3 _rand_unit_vec();
vec_3 _unit_vec_on_hemisphere(vec_3 normal);

#endif