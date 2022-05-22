#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

// Get part of string
void slice(const char *str, char *result, int start, int end)
{
    strncpy(result, str + start, end - start);
}

int main ()
{
    char s[100] = "sd56sdfsdf78sdf123sdf543s3000s";
    int sum = 0;
    int count = 0;
    int i = 0;

    while (i < strlen(s)) {
        if (isdigit(s[i])) {
            count++;
        } else if (count > 0) {
            char temp[100] = "";
            slice(s, temp, i - count, i);
            count = 0;
            sum += atoi(temp);
        }


        i++;
    }
    
    printf("%d \n", sum);

    return 0;
}