#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    char s[100] = "qwertwyuiopetuop";
    char news[100] = "";
    for (char *i = s; *i != '\0'; i++) {
        if (!is_repeat(s, i)) {
            strncat(news, i, 1);
        }
    }
    
    printf("%s\n", news);

    return 0;
}