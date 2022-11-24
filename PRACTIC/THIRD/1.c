#include <stdio.h>
#include <math.h>

double square(double a,double b,double c){
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
    double s,a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    s = square(a,b,c);
    printf("%lf",s);
    return 0;
}