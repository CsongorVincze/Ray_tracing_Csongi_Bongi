#include <stdio.h>
#include <math.h>

#include "vec_3.h"
#include "color.h"


int main(void){
    
    //kep meretek
    int image_height = 256;
    int image_width = 256;
    const char nev[] = "Papi.txt";

    FILE *fp;
    fp = fopen(nev, "w");
    fprintf(fp, "P3\n%d %d\n255\n", image_width, image_height);
    printf("Innentol jon a rendes adat!");

    //itt most asszem csinalunk egy szines kepet
    for(int j = 0; j < image_height; j++){
        fprintf(stderr, "\rProcessed lines: %d / %d", j+1, image_height);
        fflush(stderr);
        for(int i = 0; i < image_width; i++){
            color szinecske = {(double)i/(double)(image_width - 1), (double)j/(double)(image_height - 1), 0}; 
            _color_divider(szinecske, fp);            
        }
    }
    fclose(fp);
    fprintf(stderr, "\nDone.\n");


    return 0;
}