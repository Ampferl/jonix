#include "cmath.h"

int64_t round(double x){
    if (x < 0.0){
        return (x - 0.5);
    }else{
        return (x + 0.5);
    }
}