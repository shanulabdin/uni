#include <stdio.h>
#include <string.h>

int main() {
    char str[100], longest[100], word[100];
    int i, j = 0, max = 0;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);

    for (i = 0; ; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0';

            if (j > max) {
                max = j;
                strcpy(longest, word);
            }

            j = 0;

            if (str[i] == '\0') {
                break;
            }
        } else {
            word[j] = str[i];
            j++;
        }
    }

    printf("Longest word: %s", longest);

    return 0;
}