#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0, end, i;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);

    for (i = 0; ; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            end = i - 1;

            while (end >= start) {
                printf("%c", str[end]);
                end--;
            }

            if (str[i] == ' ') {
                printf(" ");
                start = i + 1;
            }

            if (str[i] == '\0') {
                break;
            }
        }
    }

    return 0;
}