#include <stdio.h>

#define mas_max 35

int main(){
    long int a[mas_max],b[mas_max];
    int n;
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%li",&a[i]);
    }
    if(n % 2 == 0){
        for(int i=0;i<n;i=i+2){
            b[i] = a[i+1];
        }
        for(int i = 1;i<n;i=i+2){
            b[i] = a[i-1];
        }
    }
    else{
        for(int i=0;i<n-1;i=i+2){
            b[i] = a[i+1];
        }
        for(int i = 1;i<n-1;i=i+2){
            b[i] = a[i-1];
        }
        b[n-1] = a[n-1];
    }
    for(int i = 0;i<n;i++){
        printf("%li ",b[i]);
    }
    return 0;
}
