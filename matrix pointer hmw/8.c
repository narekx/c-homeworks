#include <stdio.h>

#define N 4
#define M 5

int ceil_num (int num)
{
    return num % 2 ? num / 2 + 1 : num / 2;
}

int change_values (int (*arr)[M], int first_row, int first_column)
{
    int second_row = first_row + ceil_num(N);
    int second_column = first_column + ceil_num(M);

    int t = *(*(arr + first_row) + first_column);
    *(*(arr + first_row) + first_column) = *(*(arr + second_row) + second_column);
    *(*(arr + second_row) + second_column) = t;

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

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < M / 2; j++)
        {
            change_values(arr, i, j);
        }
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