#include <stdio.h>

int main(){
    int x, maxx=-1000000, minx = 1000000;
    float res;
    while(x != 0){
        scanf("%d",&x);
        if((x > maxx)&&(x!=0)){
            maxx = x;
        }
        if((x < minx)&&(x!=0)){
            minx = x;
        }
    }
    res = (float)minx/maxx;
    printf("%f",res);
    return 0;
}