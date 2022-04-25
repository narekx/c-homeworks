#include <stdio.h>

#define N 4
#define M 5

int change_columns (int (*arr)[M], int first_column, int second_column, int column_length)
{
    for (int i = 0; i < column_length; i++) {
        int t = *(*(arr + i) + first_column);
        *(*(arr + i) + first_column) = *(*(arr + i) + second_column);
        *(*(arr + i) + second_column) = t;
    }

    return 0;
}

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 1},
        {2, 3, 4, 5, 6},
        {7, 8, 9, 1, 2}
    };

    for (int i = 0; i < M / 2; i++) {
        change_columns(arr, i, M - 1 -i, N);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}