#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

bool in_array (int *arr, int *arr_end, int num)
{
    for (int *i = arr; i < arr_end; i++) {
        if (*i == num) {
            return true;
        }
    }

    return false;
}

bool is_like (int *row, int *row_end, int *like_row, int *like_row_end)
{
    for (int *i = row; i < row_end; i++) {
        if (!in_array(like_row, like_row_end, *i)) {
            return false;
        }
    }

    return true;
}

int main () {
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 4, 7, 8, 1},
        {4, 2, 5, 3, 1},
        {1, 3, 2, 4, 5}
    };

    int like_row = 0;
    int count = 0;

    for (int i = 1; i < N; i++) {
        if (is_like(*(arr + i), *(arr + i) + M, *(arr + like_row), *(arr + like_row) + M)) {
            printf("%d\n", i);
        }
    }
}