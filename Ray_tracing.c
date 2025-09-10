#include <stdio.h>



int main(void){
    
    //kep meretek
    int image_height = 256;
    int image_width = 256;

    printf("P3\n%d %d\n255\n", image_width, image_height);


    //itt most asszem csinalunk egy szines kepet
    for(int j = 0; j < image_height; j++){
        for(int i = 0; i < image_width; i++){
            double r = (double)i / (double)(image_width-1);
            double g = (double)j / (double)(image_height-1);
            double b = 0.0;

            int in_r = (int)(255.999*r);
            int in_g = (int)(255.999*g);
            int in_b = (int)(255.999*b);

            printf("%d %d %d\n", in_r, in_g, in_b);
        }
    }

    return 0;
}