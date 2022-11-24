#include <stdio.h>
#include <math.h>

int main(){
    float  x1,y1,x2,y2,x3,y3,x4,y4;
    float x,y,k1,k2,k3,k4;
    scanf("%f %f %f %f %f %f %f %f %f %f", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x,&y);
    k1 = (x2-x1)*(y-y1)-(y2-y1)*(x-x1);
    k2 = (x3-x2)*(y-y2)-(y3-y2)*(x-x2);
    k3 = (x4-x3)*(y-y3)-(y4-y3)*(x-x3);
    k4 = (x1-x4)*(y-y4)-(y1-y4)*(x-x4);
    if ((k1>=0) && (k2>=0) && (k3>=0) && (k4>=0)) printf("YES");
    else if((k1<=0) && (k2<=0) && (k3<=0) && (k4<=0)) printf("YES");
    else printf("NO");
}