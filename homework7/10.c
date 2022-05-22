#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int push_right (char *str, int index, int dif)
{
    int i = strlen(str) + dif;
    while (i > index) {
        str[i] = str[i - dif];
        printf("%c\n", str[i]);
        i--;
    }

    return 0;
}

int main ()
{
    char str[100] = "asddfsghsdf sdfgsdfg dsfg dsfgsdf dfsg sdfgsdfg dsfgsdfg";

    int start = 0;
    int end = 0;
    while (end <= strlen(str)) {
        if (str[end] == ' ' || str[end] == '\0') {
            char length[2];
            sprintf(length, "%d", end - start);
            push_right(str, end, strlen(length));
            break;
            str[end] = '&';
            end++;
            start = end + 1;
        }

        end++;
    }

    printf("%s\n", str);


    return 0;
}