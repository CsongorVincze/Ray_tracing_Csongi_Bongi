#include "intervals.h"

bool interval_contains(interval i, double x){
    if(i.min <= x && x <= i.max){
        return true;
    }
    return false;
}

bool interval_surrounds(interval i, double x){
    if(i.min < x && x < i.max){
        return true;
    }
    return false;
}
