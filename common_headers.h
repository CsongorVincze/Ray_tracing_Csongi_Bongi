#ifndef COMMON_HEADERS.H
#define COMMON_HEADERS.H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "vec_3.h"
#include "ray.h"
#include "color.h"

const double infinity = INFINITY;
const double pi = 3.1415926535897932385;

static inline double _deg_to_rad(double deg){
    return deg/180.0 * pi;
}

#endif