#include <stdio.h>

int averageOf(int, int, int);

int main() {
    int a = 0, c = 0, b = 0, avg;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("Enter value of c: ");
    scanf("%d", &c);

    avg = averageOf(a, b, c);

    printf("\nAverage of 3 inputs: %d", avg);
    return 0;
}

int averageOf(int a, int b, int c)
{
    int sum = a+b+c;
    int avg = sum/3;

    return avg;
}