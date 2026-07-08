#include <stdio.h>

int main()
{
    int a, b, i, j;
    int arr[10][10];

    printf("Enter rows and cols: ");
    scanf("%d %d", &a, &b);


    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            printf("Enter arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    return 0;
}