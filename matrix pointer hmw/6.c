#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

int *max_in_row (int *arr, int *arr_end) 
{
    int *max = arr;
    for (int *i = arr + 1; i < arr_end; i++) {
        if (*max < *i) {
            max = i;
            printf("%p  %p\n", max, i);
        }
    }
    
    return max;
}

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 3, 5},
        {3, 4, 7, 8, 1},
        {4, 2, 7, 6, 6},
        {1, 3, 20, 4, 5}
    };
    
    
    for (int i = 0; i < N; i++) {
        int *max = max_in_row(*(arr + i), *(arr + i) + M);
        printf("%d\n", *(max + M) );
        
        break;
    }
    

    return 0;
}
