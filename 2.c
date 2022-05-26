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

int strncount (char *str1, char *str2)
{
    char strn[100] = "";

    for (char *i = str1; *i != '\0'; i++) {
        if (!in_str(strn, *i) && !in_str(str2, *i)) {
            strncat(strn, i, 1);
        }
    }
    
    return strlen(strn);
}

int main()
{
    char s1[100] = "qwertyasd";
    char s2[100] = "asdfghjqwm";
    int n1 = strncount(s1, s2);
    int n2 = strncount(s2, s1);
    printf("%d %d\n", n1, n2);

    return 0;
}