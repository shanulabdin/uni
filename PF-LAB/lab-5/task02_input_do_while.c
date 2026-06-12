#include <stdio.h>

int main()
{
    int x;
    do {
        printf("Enter a number (negative to stop): ");
        scanf("%d", &x);
    } while (x >= 0);
    return 0;
}
