#include <stdio.h>

int main() {
    int count;

    printf("Enter total count of numbers: ");
    scanf("%d", &count);

    for (int i = 1; i <= count; i++) {
        printf("%d\n", i);
    }

    return 0;
}