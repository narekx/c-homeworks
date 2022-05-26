#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool in_str (char *str, char s)
{
    for (char *i = str; *i != '\0'; i++) {
        if (*i == s) {
            return true;
        }
    }

    return false;
}

int main()
{
    char s1[100] = "asfsgsdfgshfjhjdghaDc";
    char s2[100] = "dfgdfsghdfhdfhdfghdfhdfc";
    char s3[100] = "";
    char ch = 'a';

    for (char *i = s1; *i != '\0'; i++) {
        if (!in_str(s3, *i) && in_str(s2, *i)) {
            strncat(s3, i, 1);
        }
    }

    printf("%s\n", s3);

    return 0;
}