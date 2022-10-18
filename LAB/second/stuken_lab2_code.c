#include <stdio.h>
#define MAS_MAX 10000
int main(){
    double mas[MAS_MAX];
    int n,num = -1;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%lf",&mas[i]);
    }
    for(int j = 0;(j < n)&&(num == -1);j++){
        if(mas[j] < 0){
            num = j;
        }
    }
    if(num != -1){
        printf("YES\n");
        for(int i = 0;i < num;i++){
            printf("%.2lf ",mas[i]);
        }
        for(int i = n - 1;i > num;i--){
            printf("%.2lf ",mas[i]);
        }
    }
    else{
        printf("NO");
    }
    return 0;
}