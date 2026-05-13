#include <stdio.h>

int minOf(int, int, int);

int main() {
    int a = 0, c = 0, b = 0, min;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("Enter value of c: ");
    scanf("%d", &c);

    min = minOf(a, b, c);

    printf("\nMinimum of 3 inputs: %d", min);
    return 0;
}

int minOf(int a, int b, int c)
{
    int min;
    
    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }

    return min;
}