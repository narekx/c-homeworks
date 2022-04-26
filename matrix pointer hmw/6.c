#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

int max_in_row (int (*arr)[M], int row, int row_length)
{
    int max = 0;
    for (int i = 1; i < row_length; i++) {
        if (*(*(arr + row) + max) < *(*(arr + row) + i)) {
            max = i;
        }
    }

    return max;
}

bool check_min_in_column (int (*arr)[M], int row, int column, int column_length)
{
    for (int i = 0; i < column_length; i++) {
        if (*(*(arr + row) + column) >= *(*(arr + i) + column) && row != i) {
            return false;
        }
    }

    return true;
}

int main()
{
    int arr[N][M] = {
        {1, 2, 19, 11, 5},
        {3, 9, 18, 10, 1},
        {4, 2, 15, 14, 6},
        {1, 3, 20, 15, 5}
    };

    bool find = false;
    
    for (int i = 0; i < N; i++) {
        int column = max_in_row(arr, i, M);
        if (find = check_min_in_column(arr, i, column, N)) {
            printf("%d\n", *(*(arr + i) + column));
            break;
        }
    }

    if (!find) {
        printf("%s\n", "NO");
    }
    

    return 0;
}
