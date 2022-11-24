#include <stdio.h>

void transp(int (*matrix)[64],int n,int m) {
    int t;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (j > i) {
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
            
        }
    }
}

