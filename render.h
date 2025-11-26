#ifndef RENDER_H
#define RENDER_H
// ey a kameranak es a nezoportalnak allokalt header falj

#include "common_headers.h"
#include "hittable.h"
#include "sphere.h"



void viewport_creator(int image_width, int* image_height, double aspect_ratio, double focal_length, double viewport_height, double* viewport_width, point_3 camera_center, vec_3* viewport_h,
                    vec_3* viewport_v, vec_3* delta_h, vec_3* delta_v, point_3* upper_left, point_3* kezdo_pix){

    *image_height = (int)(image_width / aspect_ratio);
    *image_height = (*image_height < 1) ? 1 : *image_height; // biztositja h legyen mindig min 1 magassagu
    //
    *viewport_width = viewport_height * (double)(image_width)/(double)(*image_height);
    //
    *viewport_h = (vec_3){{*viewport_width, 0, 0}}; //? ez mukodik?
    *viewport_v = (vec_3){{0, -viewport_height, 0}};

    // nezoport pixelvektorai
    vec_3 na_h = _mul_s((1/(double)image_width), *viewport_h); *delta_h = na_h;  // vizszintesen
    vec_3 na_v = _mul_s((1/(double)(*image_height)), *viewport_v); *delta_v = na_v; //fuggolegesen

    *upper_left = _add( _add(_create(0.0, 0.0, focal_length), camera_center), _mul_s(-0.5, _add(*viewport_h, *viewport_v)));
    *kezdo_pix = _add(*upper_left, _mul_s(0.5, _add(*delta_h, *delta_v)));

}



// ez a fuggveny szinez ki egy pixelt

color ray_color(sphere sp_array[], int num_spheres, ray_3 ray, hit_rec *hitdata) {// itt mi a tokom van
    
    if(which_hit(sp_array, num_spheres, ray, (interval){.min = 0.0, .max = 20.0}, hitdata)){
        // vec_3 direction = _unit_vec_on_hemisphere();
        return _mul_s(0.5, _add(_element(1.0), hitdata -> normal));
    }
    
    vec_3 unit_ray = _unit_vec(ray.dir);
    double a = 0.5 * (unit_ray.e[1] + 1.0);
    return _add(
        _mul_s((1.0 - a), _create(0., 0., 1.0)),
        _mul_s(a, _create(1., 1., 1.))
    );
}

vec_3 rand_square() {
    return _create(rand_01() - 0.5, rand_01() - 0.5, 0.0);
}

void render(int image_width, int image_height, point_3 camera_center, vec_3 delta_h, vec_3 delta_v, point_3 kezdo_pix, sphere sp_array[], int num_spheres, FILE* fp){
    // vegigiteralunk az egesz nezoportalunkon
    int mosas = 10;
    for(int j = 0; j < image_height; j++){
        for(int i = 0; i < image_width; i++){
            color pixel_color;
            pixel_color = _element(0);
            hit_rec hitdata;
            for(int m = 0; m < mosas; m++){
                vec_3 lokdoses = rand_square();
                point_3 pix = _add(kezdo_pix, _add(_mul_s(i + lokdoses.e[0], delta_h), _mul_s(j + lokdoses.e[1], delta_v))); // pixel koord
                vec_3 ray_vec = _add(pix, _neg(camera_center)); // az a vektor ami a kamerabol a pixelbe megy
                ray_3 sugarka = {pix, ray_vec};
                pixel_color = _add(pixel_color, ray_color(sp_array, num_spheres, sugarka, &hitdata)); //? itt ez az egesz elmosos folyamat egy kicsi furan mukodik
            }        
            _color_divider(_mul_s((double)1/mosas, pixel_color), fp);
        }
    }
    fclose(fp);
}







#endif