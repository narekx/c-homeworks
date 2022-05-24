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
    char s[100] = "s-20d5.6sdfsdf7.8sdf123s45df54.3s30.00s";
    float sum = 0;
    int count = 0;
    bool dot = false;

    int i = 0;
    while (i < strlen(s)) {
        if (isdigit(s[i])) {
            count++;
        } else if (s[i] == '.' && !dot) {
            dot = true;
            count++;
        } else if (count > 0) {
            char temp[100] = "";
            slice(s, temp, i - count, i);
            float num = atof(temp);
            if (s[i - count - 1] == '-') {
                num *= -1;
            }
            
            sum += num;
            count = 0;
            dot = false;
        }

        i++;
    }
    
    printf("%f \n", sum);

    return 0;
}