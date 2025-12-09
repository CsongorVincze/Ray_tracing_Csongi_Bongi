#ifndef COMMON_HEADERS_H
#define COMMON_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "vec_3.h"
#include "ray.h"
#include "color.h"
#include "intervals.h"

const double infinity = INFINITY;
const double pi = 3.1415926535897932385;
//todo: itt amit nem hasznalunk egyaltalan azt toroljuk ki

static inline double _deg_to_rad(double deg){
    return deg/180.0 * pi;
}

// felirat a program inditasakor

void printCaption() {
    printf("   _____       __                    \n");
    printf("  / ___/____  / /_  ___  ________    \n");
    printf("  \\__ \\/ __ \\/ __ \\/ _ \\/ ___/ _ \\   \n");
    printf(" ___/ / /_/ / / / /  __/ /  /  __/   \n");
    printf("/____/ .___/_/ /_/\\___/_/   \\___/    \n");
    printf("    /_/                              \n");
    printf("    ____                 __          \n");
    printf("   / __ \\___  ____  ____/ /__  _____ \n");
    printf("  / /_/ / _ \\/ __ \\/ __  / _ \\/ ___/ \n");
    printf(" / _, _/  __/ / / / /_/ /  __/ /     \n");
    printf("/_/ |_|\\___/_/ /_/\\__,_/\\___/_/      \n");
    printf("\n");
}



#endif