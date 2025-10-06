#ifndef COLOR_H
#define COLOR_H

#include "vec_3.h"

#include <stdio.h>
#include <math.h>

typedef vec_3 color;

int _color_divider(color v, FILE* fp){
    int rbyte = (int)(255.999 * v.e[0]); // a bejovo vec_3 tipust szetdobjuk rgb-re
    int gbyte = (int)(255.999 * v.e[1]);
    int bbyte = (int)(255.999 * v.e[2]);

    fprintf(fp, "%d %d %d\n", rbyte, gbyte, bbyte);
}


#endif