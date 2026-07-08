#include <stdio.h>

int main()
{
    int a[10][10];
    int rows, cols;
    int i, j, k, temp;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
          printf("Enter element a[%d][%d]: ", i, j);
          scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < rows; i++){
      for(j = 0; j < cols - 1; j++){
        for(k = j + 1; k < cols; k++){
          if(a[i][j] > a[i][k]){
            temp = a[i][j];
            a[i][j] = a[i][k];
            a[i][k] = temp;
          }
        }
      }
    }

    printf("\nSorted Array:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}