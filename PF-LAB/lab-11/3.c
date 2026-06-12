#include <stdio.h>

int main() {
    int a = 25;
    int *p = &a;
    int **dp = &p;

    printf("Value = %d", **dp);

    return 0;
}