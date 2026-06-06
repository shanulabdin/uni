#include <stdio.h>

int sumOf(int n)
{
    if(n < 1){
        printf("\nReached base case with: %d", n);

        return 0;
    }
    
    printf("\nStack Rolling with sumOf(%d)", n);
    int sum = n + sumOf(n-1);

    printf("\nStack Unrolling with sumOf(%d)", n);
    return sum;
}


int main() {
    int n, sum;
    printf("Enter value of n: ");
    scanf("%d", &n);

    sum = sumOf(n);
    printf("\nSum: %d", sum);

    return 0;
}