#include <stdio.h>

int main(){
    int a,b,c,max,min;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    if(a>b){
        max = a;
    }
    if(b>a){
        max = b;
    }
    if(max>c){
        max = max;
    }
    if(max<c){
        max = c;
    }
    
    if(a<b){
        min = a;
    }
    if(b<a){
        min = b;
    }
    if(min>c){
        min = c;
    }
    if(max<c){
        min = min;
    }
    
    int second = (a+b+c) - min - max;
    if((a == b) && (b == c)){
        printf("acute");
    }
    else if(max>=min+second){
        printf("impossible");
    }
    else if (min*min+second*second - max*max == 0){
        printf("right");
    }
    else if(min*min+second*second - max*max < 0){
        printf("obtuse");
    }
    else if(min*min+second*second - max*max > 0){
        printf("acute");
    }
}