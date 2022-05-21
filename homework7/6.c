#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Check char is vowel
bool is_vowel (char c)
{
    char vowels[] = "aeiouy";
    if (strchr(vowels, c)) {
        return true;
    }

    return false;
}

// Compare vowels and consonants count in word
bool is_equal (char str[])
{
    int vowels_count = 0;
    int consonants_count = 0;
    char *i = str;
    while (*i != '\0') {
        if (is_vowel(*i)) {
            vowels_count++;
        } else {
            consonants_count++;
        }

        i++;
    }

    return vowels_count == consonants_count;
}

int main ()
{
    char str[100] = "Thiiys, a sample helloo string. yaysdf";
    char newStr[200] = "";
    char * word;
    word = strtok (str, " ,.-");
    while (word != NULL) {
        if (is_equal(word)) {
            strcat(newStr, word);
            strcat(newStr, " ");
        }
        
        word = strtok (NULL, " ,.-");
    }

    printf("%s\n", newStr);
    return 0;
}