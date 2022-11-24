#include <stdio.h>

#define MAX_SIZE 10000

int main(){
int rows, cols;
scanf("%i %i", &rows, &cols);
if (rows > MAX_SIZE || cols > MAX_SIZE){
puts("Incorrect array size!");
}
else{
double m[rows + 1][cols];
for (int i = 0; i < rows; i++){
for (int j = 0; j < cols; j++){
scanf("%lf", &m[i][j]);
m[rows][j] += m[i][j];
}
}
for (int j = 0; j < cols; j++){
m[rows][j] /= (double) rows;
}

for (int i = 0; i < rows + 1; i++){
for (int j = 0; j < cols; j++){
printf("%6.2lf", m[i][j]);
}
puts("");
}
}

return 0;
}