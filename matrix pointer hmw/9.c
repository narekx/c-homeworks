#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

bool check_minus (int (*arr)[M], int column, int row_length)
{
    for (int  i = 0; i < row_length; i++) {
        if (*(*(arr + i) + column) >= 0) {
            return false;
        }
    }

    return true;
}

int change_column_values (int (*arr)[M], int first_column, int second_column, int row_length)
{
    for (int i = 0; i < row_length; i++) {
        int t = *(*(arr + i) + first_column);
        *(*(arr + i) + first_column) = *(*(arr + i) + second_column);
        *(*(arr + i) + second_column) = t;    
    }

    return 0;
}

int delete_column (int (*arr)[M], int column, int row_lentgh, int column_length)
{
    for (int i = column; i < column_length - 1; i++) {
        change_column_values(arr, i, i + 1, row_lentgh);
    }
}

int main()
{
    int arr[N][M] = {
        {-1, 2, -3, 4, 5},
        {-6, 7, -8, 9, 1},
        {-2, 3, -4, 5, 6},
        {-7, 8, -9, 1, 2}
    };

    int n = N;
    int m = M;
    int i = 0;
    while (i < m) {
        if (check_minus(arr, i, n)) {
            delete_column(arr, i, n, m);
            m--;
        }

        i++;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}