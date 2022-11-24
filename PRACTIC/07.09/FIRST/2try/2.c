#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1, r1, x2, y2, r2,count;
    
    scanf("%d %d %d %d %d %d",&x1, &y1, &r1, &x2, &y2, &r2);

    int ras2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    int razn_radiuses2 = (r2-r1) * (r2-r1); 
    int sum_radiuses2 = (r2+r1) * (r2+r1);

    if((x1 == x2)&&(y2 == y1)&&(r1 == r2)){ // окружности совпадают!
        count = 3;
    }
    else if(ras2 == sum_radiuses2){ //внешнее касание
        count = 1;
    }
    else if(ras2 == razn_radiuses2){ //внутреннее касание
        count = 1;
    }
    else if(ras2 < razn_radiuses2){ //не касаются друг друга внутри
        count = 0;
    }
    else if(ras2 < sum_radiuses2){ //внешнее пересечение
        count = 2;
    }
    else if(ras2 > razn_radiuses2){ //внутренее пересечение
        count = 2;
    }
    else if(ras2 > sum_radiuses2){ //далеко друг от друга
        count = 0;
    }
    
    if (count == 0){ //ноль точек пересечения
        printf("0");
        return 0;
    }
    else if(count == 3){ //окружности совпадают - бесконечное кол-во точек пересечения
        printf("3");
        return 0;
    }
    else{ //обрабатываем все остальные случаи, ищем общие точки

        printf("OK");
        return 0;

    }
    return 0;
}