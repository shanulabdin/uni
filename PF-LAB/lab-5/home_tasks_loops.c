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

    if (count > 0) {
        int i = 0;
        if (arr[0] != 0) {
            do {
                if (arr[i] == 0) break;
                printf("%d\n", arr[i]);
                i = i + 1;
            } while (i < count);
        }
    }

    int nonzero = 0;
    int j;
    for (j = 0; j < count; j = j + 1) {
        if (arr[j] != 0) nonzero = nonzero + 1;
    }
    printf("Total count (excluding zero) = %d\n", nonzero);

    return 0;
}
