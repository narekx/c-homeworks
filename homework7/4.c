#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Check str has c character
bool is_repeat (char *str, char *s)
{
    for (char *i = str; *i != '\0'; i++) {
        if (*i == *s && i != s) {
            return true;
        }
    }

    return false;
}

int main()
{
    char s[100] = "qwertyuiopeuop";
    int i = 0;
    while (i < strlen(s)) {
        if (is_repeat(s, &s[i])) {
            memmove(&s[i], &s[i + 1], strlen(s) - i);
        } else {
            i++;
        }
    }

    printf("%s\n", s);

    return 0;
}