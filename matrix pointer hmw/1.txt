#include <stdio.h>

#define N 4
#define M 5

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 4, 7, 8, 1},
        {4, 2, 7, 9, 6},
        {1, 3, 2, 4, 5}
    };
    
    int maxi = 0;
    int maxj = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (*(*(arr + maxi) + maxj) < *(*(arr + i) + j)) {
                maxi = i;
                maxj = j;
            }
        }
    }
    
    int sum = 0 - *(*(arr + maxi) + maxj);
    
    for (int i = 0; i < N; i++) {
        sum += *(*(arr + i) + maxj);

    }
    
    for (int j = 0; j < M; j++) {
        sum += *(*(arr + maxi) + j);
    }
    
    printf("%d\n", sum);

    return 0;
}
