#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    }
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }
    printf("Sum = %d\n", sum);
    return 0;
}
