#include "vec_3.h"
#include <stdio.h>
#include <math.h>
int main(){
    
vec_3 blabla = _create(1.0, 2.0, 3.0);
vec_3 bla = _negate(blabla);

printf("%.2f %.2f %.2f", bla.x, bla.y, bla.z);
    
    
    return 0;
}