#include <stdio.h>

int main(){
    int x,y,a,b,c,uravn;
    scanf("%d %d %d %d %d",&x,&y,&a,&b,&c);
    uravn = a*x+b*y+c;
    if (uravn == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}