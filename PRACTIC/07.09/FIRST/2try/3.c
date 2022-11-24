#include <stdio.h>
#include <math.h>
int main()
{
    int x1,y1,a,b,c;
    scanf("%d %d %d %d %d",&x1,&y1,&a,&b,&c);
    double sq = a*a+b*b;
    double ras = (a*x1+b*y1+c)/(sqrt(sq));
    if(ras<0){
        printf("%f",ras*(-1));
    }
    else{
        printf("%f",ras);
    }
    
}