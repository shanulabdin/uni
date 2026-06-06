#include <stdio.h>

int countDigits(int n)
{
    if (n < 10){
        printf("\nReached base case: n = %d\n", n);
        return 1;
    }

    printf("\nStack Rolling: n = %d", n);
    int count = 1 + countDigits(n/10);

    printf("\nStack Unrolling: n = %d", n);

    return count;
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int count = countDigits(n);

    printf("\nNumber of Digits: %d\n", count);

    return 0;
}