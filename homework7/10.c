#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void push_right (char *str, int index, int dif)
{
    int i = strlen(str) + dif;
    while (i > index + dif) {
        str[i] = str[i - dif];
        i--;
    }
}

int main ()
{
    char str[100] = "asddfsghsdf sdfgsdfg dsfg dsfgsdf dfsg sdfgsdfg dsfgsdfg";
    char newStr[100] = "";

    int count = 0;
    int i = 0;
    while (i < strlen(str)) {
        if (str[i] != ' ') {
            count++;
        }

        if (str[i + 1] == ' ' || str[i + 1] == '\0') {
            char word_length[3];
            sprintf(word_length, "%d", count);
            push_right(str, i, strlen(word_length));
            i++;
            int j = 0;
            while (j < strlen(word_length)) {
                str[i] = word_length[j];
                j++;
                i++;
            }

            count = 0;
        }

        i++;
    }

    printf("%s\n", str);

    return 0;
}