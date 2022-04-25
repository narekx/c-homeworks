#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5

bool check_different (int *arr, int *arr_end) 
{
    for (int *i = arr; i < arr_end - 1; i++) {
        for (int *j = i + 1; j < arr_end; j++) {
            if (*i == *j) {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    int arr[N][M] = {
        {1, 2, 3, 3, 5},
        {3, 4, 7, 8, 1},
        {4, 2, 7, 6, 6},
        {1, 3, 20, 4, 5}
    };
    
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (check_different(*(arr + i), *(arr + i) + M)) {
            printf("%d\n", i);
            count++;
        }
    }
    
    if (count == 0) {
        printf("NO\n");   
    }

    return 0;
}
