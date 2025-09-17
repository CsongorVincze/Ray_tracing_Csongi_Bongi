#include "vec_3.h"
//#include "vec_3_construct.c"
#include <stdio.h>
#include <math.h>
int main(){
    
vec_3 blabla = vec_3_create(1.0, 2.0, 3.0);
blabla = vec_3_negate(blabla);

printf("%.2f %.2f %.2f", blabla.x, blabla.y, blabla.z);
    
    
    return 0;
}