#include <stdio.h>

int main()
{
    int x;
    int count = 0;

    while (1) {
        printf("Enter number (0 to stop): ");
        scanf("%d", &x);
        if (x == 0) break;
        count = count + 1;
    }

    printf("You entered %d numbers (excluding zero)\n", count);

    return 0;
}
