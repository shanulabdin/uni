#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    
    printf("Enter a string: ", str);
    fgets(str, 100, stdin);

    while(str[i] != '\0') {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }

    printf("%s", str);

    return 0;
}