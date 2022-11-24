#include <stdio.h>


int main() {
    int angles_sign = 0, point_not_in_polygon = 0;
    float start_point_x, start_point_y;
    float end_point_x, end_point_y;
    float point_x, point_y;
    int n, i;
    float polygon_x[100];
    float polygon_y[100];
    float sign_array[100];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f%f", &polygon_x[i], &polygon_y[i]);
    }
    scanf("%f%f", &point_x, &point_y);

    start_point_x = polygon_x[n - 1];
    start_point_y = polygon_y[n - 1];
    for (i = 0; i < n; i++) {
        end_point_x = polygon_x[i];
        end_point_y = polygon_y[i];
        sign_array[i] = (point_x - end_point_x) * (start_point_y - end_point_y)
                      - (start_point_x - end_point_x) * (point_y - end_point_y);
        start_point_x = end_point_x;
        start_point_y = end_point_y;
    }

    if (sign_array[0] > 0.0) {
        angles_sign = 1;
    } else {
        angles_sign = -1;
    }
    for (i = 1; i < n; i++) {
        if ((sign_array[i] > 0.0 && angles_sign == -1) || (sign_array[i] <= 0.0 && angles_sign == 1) ) {
            printf("NO\n");
            point_not_in_polygon = 1;
            break;
        }
    }
    if (point_not_in_polygon == 0) {
        printf("YES\n");
    }
    return 0;
}