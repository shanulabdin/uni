#include <stdio.h>

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Before: %d %d\n", x, y);

    swap(&x, &y);

    printf("After: %d %d", x, y);

    return 0;
}