#include <stdio.h>

int ap1(int a0,int d, int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a0 + i*d);
    }
}

int main(){
    int a0,d,n;
    scanf("%d %d %d",&a0,&d,&n);
    ap1(a0,d,n);
    return 0;
}