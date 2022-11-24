#include <stdio.h>
#include <math.h>

int my_round(float a){
    if(a < 0){
        a = -a;
        a = -round(a);
    }
    else{
        a = round(a);
    }
    return a;
}


