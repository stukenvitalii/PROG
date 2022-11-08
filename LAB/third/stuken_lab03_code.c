#include <stdio.h> 


int main(){
    int n,m,count = 0;
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n][m];
    int b[n];
    for(int i = 0;i < n;i++){
        for(int j  = 0;j < m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i = 0;i < n;i++){
        count = 0;
        for(int j = 0;j < m;j++){
            count += a[i][j];
        }
        if(count % 2 == 0){
            b[i] = 0;
        }
        else{
            b[i] = 1;
        }
    }
    printf("\n");
    for(int i = 0;i < n;i++){
        for(int j  = 0;j < m;j++){
            printf("%d ",a[i][j]);
        }
        printf("%d\n",b[i]);
    }

    return 0;
}