#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

// int change_values (int (*arr)[M], int first_row, int first_column)
// {
//     int second_row = first_row + ceil_num(N);
//     int second_column = first_column + ceil_num(M);

//     int t = *(*(arr + first_row) + first_column);
//     *(*(arr + first_row) + first_column) = *(*(arr + second_row) + second_column);
//     *(*(arr + second_row) + second_column) = t;

//     return 0;
// }

bool check_minus (int (*arr)[M], int column, int row_length)
{
    for (int  i = 0; i < row_length; i++) {
        if (*(*(arr + i) + column) >= 0) {
            return false;
        }
    }

    return true;
}

int delete_column (int (*arr)[M], int column, int row_lentgh, int column_length)
{
    for (int i = 0;)
}

int main()
{
    int arr[N][M] = {
        {1, 2, -3, 4, 5},
        {6, 7, -8, 9, 1},
        {2, 3, -4, 5, 6},
        {7, 8, -9, 1, 2}
    };

    int n = N;
    int m = M;
    int i = 0;
    while (i < m) {
        if (check_minus(arr, i, n)) {
            delete_column(arr, i);
        }

        i++;
    }
    

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         printf("%d ", *(*(arr + i) + j));
    //     }
    //     printf("\n");
    // }
}