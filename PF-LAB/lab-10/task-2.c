#include <stdio.h>

int gcdOf(int a, int b)
{
    if (b == 0)
        return a;

    printf("Stack: a = %d, b = %d\n", a, b);

    return gcdOf(b, a % b);
}

int main()
{
    int a, b;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    int gcd = gcdOf(a, b);

    printf("\nGCD: %d\n", gcd);

    return 0;
}