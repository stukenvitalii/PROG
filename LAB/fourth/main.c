#include <stdio.h>
#include <stdlib.h>

void scan_row(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int form_row(int *a, int *b, int rows)
{
    int not_decreasing = 1;
    for (int i = 0; (i < rows - 1) && (not_decreasing); i++)
    {
        if (a[i] > a[i + 1])
        {
            not_decreasing = 0;
        }
    }
    if (not_decreasing)
    {
        for (int i = 0; i < rows; i++)
        {
            b[i] = a[i];
        }
    }
    return not_decreasing;
}

int main()
{
    int rows, mx;
    int cols;
    scanf("%d", &cols);
    int a[cols];
    scan_row(a, cols);
    mx = a[0];
    for (int i = 0; i < cols; i++)
    {
        if (abs(a[i]) > abs(mx))
        {
            mx = abs(a[i]);
        }
    }

    rows = mx;
    int arr[rows][cols];
    for (int i = 0; i < cols; i++)
        arr[0][i] = a[i];
    for (int i = 1; i < rows; i++)
    {
        scan_row(arr[i], cols);
    }
    int out_arr[cols][rows];
    int curr_row = 0;
    for (int i = 0; i < cols; i++)
    {
        int curr_col[rows];
        for (int j = 0; j < rows; j++)
        {
            curr_col[j] = arr[j][i];
        }
        if (form_row(curr_col, out_arr[curr_row], rows))
        {
            curr_row++;
        }
    }

    for (int i = 0; i < curr_row; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", out_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
