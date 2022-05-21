#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Check str has c character
bool is_repeat (char *str, char *s)
{
    // printf("%s\n", str);
    char *i = str;
    while (*i != '\0' && *i != ' ') {
        if (*i == *s && i != s) {
            return true;
        }    

        i++;
    }

    return false;
}

// Remove chars in str
int remove_chars (char *str, char c)
{
    char i = 0;
    while (str[i] != '\0' && str[i] != ' ') {
        if (str[i] == c) {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
        } else {
            i++;
        }
    }

    return 0;
}

int main()
{
    char s[100] = "qweqret yuiqopeyuop fdgdasfmgdf";
    int i = 0;
    while (i < strlen(s)) {
        if (s[i] != ' ' && is_repeat(s + i, &s[i])) {
            remove_chars(s + i, s[i]);
        } else {
            i++;
        }
    }

    printf("%s\n", s);
    return 0;
}