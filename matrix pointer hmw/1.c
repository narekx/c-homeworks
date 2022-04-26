#include <stdio.h>

#define N 4
#define M 5

int get_max (int (*arr)[M], int column_length, int row_length)
{
    int max = **arr;
    
    for (int i = 0; i < column_length; i++) {
        for (int j = 0; j < row_length; j++) {
            if (max < *(*(arr + i) + j)) {
                max = *(*(arr + i) + j);
            }
        }
    }

    return max;
}

int get_row_sum (int (*arr)[M], int row, int row_length)
{
    int sum = 0;
    for (int i = 0; i < row_length; i++) {
        sum += *(*(arr + row) + i);
    }

    return sum;
}

int get_column_sum (int (*arr)[M], int column, int column_length)
{
    int sum = 0;
    for (int i = 0; i < column_length; i++) {
        sum += *(*(arr + i) + column);
    }

    return sum;
}

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 4, 7, 8, 1},
        {4, 2, 7, 9, 6},
        {1, 9, 2, 4, 5}
    };

    int max = get_max(arr, N , M);

    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (*(*(arr + i) + j) == max) {
                sum -= max;
                sum += get_row_sum(arr, i, M);
                sum += get_column_sum(arr, j, N);
            }
        }
    }
    
    printf("%d\n", sum);

    return 0;
}