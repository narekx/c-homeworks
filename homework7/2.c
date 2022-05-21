#include <stdio.h>
#include <string.h>

//  Get str1 not repeated character count in str2
int get_not_repeat_count (char str1[], char str2[])
{
    char not_repeat[100] = "";
    for (char *i = str1; *i != '\0'; i++) {
        if (!strchr(not_repeat, *i) && !strchr(str2, *i)) {
            strncat(not_repeat, i, 1);
        }
    }

    return strlen(not_repeat);
}

int main ()
{
    char s1[100] = "qwertyuisfhk";
    char s2[100] = "asdfghjklqetu";

    printf("s1 not repeat count %d\n", get_not_repeat_count(s1, s2));
    printf("s2 not repeat count %d\n", get_not_repeat_count(s2, s1));


    return 0;
}