//EZ IGAZABOL UGYAN AZT CSINALJA MINT A STATIKUS CSAK TOBB KEPET GENERAL ES UGYESEN OSSZEFUZI






#include "common_headers.h"
#include "hittable.h"
#include "sphere.h"
#include "hit_list.h"
#include "animation.h"
#include "render.h"



int main(void){
    
    //kep meretek
    int image_width = 1024/4;
    int image_height;
    double aspect_ratio = 16.0/9.0;

    // nezoportal meretek
    double focal_length = 3.0;
    double viewport_height = 2.0; 
    double viewport_width;
    point_3 camera_center = {0., 0., 0.};

    // nezoport szelein levo vektorok
    vec_3 viewport_h;
    vec_3 viewport_v;

    // nezoport pixelvektorai
    vec_3 delta_h;
    vec_3 delta_v;

    point_3 upper_left;
    point_3 kezdo_pix;

    viewport_creator(image_width, &image_height, aspect_ratio, focal_length, viewport_height, &viewport_width, camera_center, &viewport_h,
                    &viewport_v, &delta_h, &delta_v, &upper_left, &kezdo_pix);

    int max_pattogas = 10;


    
    
    //letrehozzuk a gomboket
    int num_spheres = 1;
    sphere sp_array[num_spheres]; //todo: ez majd kesobb lehetne rendesen object array
    _rand_spheres(num_spheres, sp_array); // letrehozunk valamennyi random parameteru gombot

    // most az egeszbol csinalunk egy nagy loopot h tobb "kepkockat" tudjunk generalni
    int num_frames = 50;
    for(int k = 0; k < num_frames; k++){
        

        // fileba iras
        char nev[12];
        sprintf(nev, "Frame_%03d.ppm", k);
        FILE *fp;
        fp = fopen(nev, "w");
        fprintf(fp, "P3\n%d %d\n255\n", image_width, image_height);
        // printf("Innentol jon a rendes adat!\n");
        
        render(image_width, image_height, camera_center, delta_h, delta_v, kezdo_pix, sp_array, num_spheres, fp);


        fprintf(stderr, "\nFrame %d: Done.\n", k);


        // harm_osc_y(sp_array, num_spheres, 0.2, 0.3, k+1 );
        random_walk(sp_array, num_spheres);

        
    }
    
    //szolunk az op rendszernek h legyszi futtassa terminalba ezeket a parancsokat
    system("ffmpeg -y -framerate 30 -i Frame_%03d.ppm -c:v wmv2 -b:v 2000k vidi.wmv");
    

    //mostant kirolhetjuk a kepeket
    system("del Frame_*.ppm");

    //nezzuk meg a vidit
    system("start vidi.wmv");



    return 0;
}