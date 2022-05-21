#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[100] = "asaddfgdsfgsdfhfdmj";
    char s2[100] = "asddfhsfjmhdfjvcbjfgj";
    char s3[100] = "";
    for (char *i = s1; *i != '\0'; i++) {
        if (!strchr(s3, *i) && strchr(s2, *i)) {
            strncat(s3, i, 1);
        }
    }

    printf("%d\n", strlen(s3));

    return 0;
}