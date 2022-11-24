#include <stdio.h>

#define mas_max 10

int main(){
    double a[mas_max][mas_max];
    double sr[mas_max];
    int m,n,i,j,k = 0;
    double s = 0.0;
    scanf("%d %d",&m,&n);
    if(m > 10 || n > 10){
        printf("Incorrect array size!");
        return 0;
    }
    else{
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                scanf("%lf",&a[i][j]);
            }
        }
        for(j = 0;j < n;j++){
            for(i = 0;i < m;i++){
                s = s + a[i][j];
                k++;
                }
            sr[j] = s/(double)k;
            s = 0;
            k = 0;
        }

        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                printf("%6.2lf",a[i][j]);
            }
        printf("\n");
        }
        for(i = 0;i < n;i++){
            printf("%6.2lf",sr[i]);
        }
    }

}
