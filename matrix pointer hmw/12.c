#include <stdio.h>

#define N 4

int main () {
    int arr[N][N] = {
        {1, 2, 3, 0},
        {5, 0, 6, 7},
        {8, 9, 0, 11},
        {0, 15, 16, 0}
    };

    int vect[N * N];
    int j = 0;

    for (int i = 0; i < N; i++) {
        if (*(*(arr + i) +  N - 1 - i) == 0) {
            for (int k = 0; k < N; k++) {
                vect[j] = *(*(arr + k) + N - 1 - i);
                j++;
            }
        }
    }

    for (int *i = vect; i < vect + j; i++) {
        printf("%d\n", *i);
    }
}