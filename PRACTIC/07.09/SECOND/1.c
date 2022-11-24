#include <stdio.h>

#define mas_max 35

int main(){
    int a[mas_max];
    int i = 0, n,max= -1000000;
    
    scanf("%d",&n);

    while(i < n){
        scanf("%d",&a[i]);
        i++;
    }
    for(i = 0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    printf("%d",max);
    return 0;
}