#include "vec_3.h"

vec_3 _create(double x, double y, double z){
    vec_3 v = {x, y, z};
    return v;
}

vec_3 _zero(void){
    vec_3 v = {0.0, 0.0, 0.0};
    return v;
}

vec_3 _neg(vec_3 v){ //itt ez nem mukodik
    vec_3 w = _create(-v.x, -v.y, -v.z);
    return w;
}