#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "vec_3.h"
#include "color.h"
#include "ray.h"
#include "hittable.h"
#include "sphere.h"


/*
double hit_sphere(point_3 sphere_center, double radius, ray_3 ray){
    vec_3 oc = _add(sphere_center, _neg(ray.orig));
    double a = _dot(ray.dir, ray.dir);
    double h = _dot(ray.dir, oc);
    double c = _dot(oc, oc) - radius*radius;
    double discriminant = h*h - a*c;
    if(discriminant < 0){
        return -1.0;
    }
    else{
        return (h - sqrt(discriminant))/a;
    }
}
*/


color ray_color(sphere sp, ray_3 ray, hit_rec *hitdata) {
    vec_3 unit_ray = _unit_vec(ray.dir);
    double a = 0.5 * (unit_ray.e[1] + 1.0);
    if(hit_sphere(sp, ray, 0.0, 10.0, hitdata)){
        return _mul_s(0.5, _add(_element(1.0), hitdata -> normal));
    }

    /*
    if(t > 0.0){ 
        vec_3 N = _unit_vec(_add(_pos(ray, t), _neg(sphere_center))); // itt nagyon draga a unitcev
        return _mul_s(0.5, _add(_element(1.0), N));
    }
    */
    
    return _add(
        _mul_s((1.0 - a), _create(0., 0., 1.0)),
        _mul_s(a, _create(1., 1., 1.))
    );
}

int main(void){
    
    //kep meretek
    int image_width = 400;
    int image_height;
    double aspect_ratio = 16.0/9.0;
    image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; // biztositja h legyen mindig min 1 magassagu

    // nezoportal meretek
    double focal_length = 3.0;
    double viewport_height = 2.0; 
    double viewport_width = viewport_height * (double)(image_width)/(double)(image_height);
    point_3 camera_center = {0., 0., 0.};

    // nezoport szelein levo vektorok
    vec_3 viewport_h = {viewport_width, 0, 0};
    vec_3 viewport_v = {0, -viewport_height, 0};

    // nezoport pixelvektorai
    vec_3 delta_h = _mul_s((1/(double)image_width), viewport_h); // vizszintesen
    vec_3 delta_v = _mul_s((1/(double)image_height), viewport_v); //fuggolegesen

    point_3 upper_left = _add( _add(_create(0.0, 0.0, focal_length), camera_center), _mul_s(-0.5, _add(viewport_h, viewport_v)));
    point_3 kezdo_pix = _add(upper_left, _mul_s(0.5, _add(delta_h, delta_v)));

    printf("viewport_h: ");
    _vec_print(viewport_h);
    printf("viewport_v: ");
    _vec_print(viewport_v);
    printf("delta_h:    ");
    _vec_print(delta_h);
    printf("delta_v:    ");
    _vec_print(delta_v);
    printf("upper_left: ");
    _vec_print(upper_left);
    printf("kezdo_pix:  ");
    _vec_print(kezdo_pix);



    // fileba iras
    const char nev[] = "Papi.ppm";
    FILE *fp;
    fp = fopen(nev, "w");
    fprintf(fp, "P3\n%d %d\n255\n", image_width, image_height);
    printf("Innentol jon a rendes adat!");

    //itt most asszem csinalunk egy szines kepet
    
    sphere sp; //ez tarolja a gomb adatait
    sp.center = _create(0.0, 0.0, 5.0);
    sp.radius = 1.0;
    hit_rec hitdata; // ebbe taroljuk majd a gombbel valo utk. adatait

    for(int j = 0; j < image_height; j++){
        fprintf(stderr, "\rProcessed lines: %d / %d", j+1, image_height);
        fflush(stderr);
        for(int i = 0; i < image_width; i++){
            point_3 pix = _add(kezdo_pix, _add(_mul_s(i, delta_h), _mul_s(j, delta_v))); // pixel koord
            vec_3 ray_vec = _add(pix, _neg(camera_center)); // az a vektor ami a kamerabol a pixelbe megy
            ray_3 sugarka = {pix, ray_vec};
            _color_divider(ray_color(sp, sugarka, &hitdata), fp);            
        }
    }
    fclose(fp);
    fprintf(stderr, "\nDone.\n");

    
   


    return 0;
}