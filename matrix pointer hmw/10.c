#include <stdio.h>

#define N 4
#define M 5

int sort_arr (int *arr, int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int sort_matrix (int (*arr)[M], int rows_count, int columns_count)
{
    for (int i = 0; i < rows_count; i++) {
        sort_arr(*(arr + i), columns_count);
    }
}

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 4, 7, 8, 1},
        {4, 2, 7, 9, 6},
        {1, 9, 2, 4, 5}
    };

    sort_matrix(arr, N, M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}