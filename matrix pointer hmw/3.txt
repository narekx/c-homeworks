#include <stdio.h>

#define N 4
#define M 5

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 4, 7, 8, 1},
        {4, 2, 7, 9, 6},
        {1, 3, 20, 4, 5}
    };
    
    int max[M]; 
    
    for (int i = 0; i < M; i++) {
        *(max + i) = *(*(arr) + i);
        for (int j = 0; j < N; j++) {
            if (*(max + i) < *(*(arr + j) + i)) {
                *(max + i) = *(*(arr + j) + i);    
            }
        }
    }
    
    int min = *max;
    for (int i = 1; i < M; i++) {
        if (min > *(max + i)) {
            min = *(max + i);
        }
    }
    
    printf("%d\n", min);

    return 0;
}
