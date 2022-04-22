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
    
    int max = 0;
    int maxj;
    
    for (int i = 0; i < M; i++) {
        int p = 1;
        for (int j = 0; j < N; j++) {
            p *= *(*(arr + j) + i);
        }
        
        if (p > max) {
            max = p;
            maxj = i;
        }
    }
    
    printf("%d\n", maxj);

    return 0;
}
