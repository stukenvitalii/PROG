#include <stdio.h>

#define mas_max 10000

int main(){
    long int a[mas_max];
    int n,k = 0;
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%li",&a[i]);
    }
    for(int i = 1;i<n;i++){
        //printf("%li %li",a[i],a[i-1]);
        if (a[i] > a[i-1]){
            k++;
            
        }
    }
    printf("%d",k);
    return 0;
}