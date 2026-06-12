#include <stdio.h>

int main()
{
    int x;
    while (1) {
        printf("Enter number (0 to stop): ");
        scanf("%d", &x);
        if (x == 0) break;
    }
    return 0;
}
