#ifndef VEC_3_H
#define VEC_3_H

typedef struct {
    double x, y, z;
} vec_3;

vec_3 vec_3_create(double x, double y, double z);
vec_3 vec_3_zero(void);
vec_3 vec_3_negate(vec_3 v);

#endif