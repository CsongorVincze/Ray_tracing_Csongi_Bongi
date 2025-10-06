#include <stdio.h>
#include <math.h>
#include "vec_3.h"
#include "color.h"
#include "ray.h"

int main(){

point_3 org = {1., 4., 8.};
vec_3 dir = {1., 1., 1.};
double t = 2;

point_3* newpos = position(org, dir, t);

_vec_print(*newpos);





return 0;
}