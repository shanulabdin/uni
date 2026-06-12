#include <stdio.h>

int main()
{
    int arr[100];
    int count = 0;
    int x;
    while (1) {
        printf("Enter number (0 to stop): ");
        scanf("%d", &x);
        arr[count] = x;
        count = count + 1;
        if (x == 0) break;
        if (count >= 100) break;
    }

    int i = 0;
    if (count > 0) {
        do {
            if (arr[i] == 0) break;
            printf("%d\n", arr[i]);
            i = i + 1;
        } while (i < count);
    }
    return 0;
}
