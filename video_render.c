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

    printf("Milyen felbontast szeretnel? (szelesseg pixelekben) (elfogadhato ertekek: 2^n, ahol n egesz es 4 < n < 11)\n");
    printf("Enter a resolution (width in pixels) (acceptable inputs: 2^n, where n is an intiger and 4 < n < 11)\n");
    while(scanf("%d", &image_width) != 1 || image_width % 2 != 0 || image_width < 32 || image_width > 1024){
        printf("Helytelen formatum! / Incorrect format!\n");
        while(getchar() != '\n');
    }

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
    int num_spheres = 5;
    
    printf("Hany gombot szeretnel? (ajanlott: 2-10) / How many spheres do you want? (recomended: 2-10)\n");
    int a;
    scanf("%d", &a);
    num_spheres = a+1; // itt valamiert nem mukodott ha kapasbol a num_spheres-be olvastam be
    
    // dinamikusan allokalunk memoriat a gomboknek
    sphere* sp_array = (sphere*) malloc(sizeof(sphere) * num_spheres);
    if(sp_array == NULL){
        fprintf(stderr, "A memoria allokaico nem sikerult! / Memory allocation failed");
        return 1;
    }

    sp_array[0].center = _create(0.0, -100.0, 6.0);
    sp_array[0].radius = 100.0;
    _rand_spheres(num_spheres, sp_array); // letrehozunk valamennyi random parameteru gombot

    // most az egeszbol csinalunk egy nagy loopot h tobb "kepkockat" tudjunk generalni
    int num_frames = 100;
    printf("Milyen hosszu videot szeretnel? (a video 30fps-en fut, ajanlott: 1-10, egesz szam elfogadott) / How long video do you want? (video is running on 30 fps, recomended: 1-10, intiger value accepted)\n");
    int seconds;
    scanf("%d", &seconds);
    num_frames = 30*seconds;

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


        harm_osc_y(sp_array, num_spheres, 0.2, 0.3, k+1 );
        // random_walk(sp_array, num_spheres);

        
    }
    
    //szolunk az op rendszernek h legyszi futtassa terminalba ezeket a parancsokat
    system("ffmpeg -y -framerate 30 -i Frame_%03d.ppm -c:v wmv2 -b:v 2000k vidi.wmv");
    

    //mostant kirolhetjuk a kepeket
    system("del Frame_*.ppm");

    //nezzuk meg a vidit
    system("start vidi.wmv");



    free(sp_array);

    return 0;
}