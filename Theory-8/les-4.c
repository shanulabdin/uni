#include <stdio.h>

int main()
{

  int i, j;
  int arr1[2][3], arr2[2][3], sumArr[2][3];

  printf("\nEnter Values for Array 1:\n");

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("Enter element [%d][%d]: ", i, j);
      scanf("%d", &arr1[i][j]);
    }
  }
  printf("\nEnter Values for Array 2:\n");

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("Enter element [%d][%d]: ", i, j);
      scanf("%d", &arr2[i][j]);
    }
  }
  printf("\nSum of Arrays:\n");

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      sumArr[i][j] = arr1[i][j] + arr2[i][j];

      printf("%d ", sumArr[i][j]);
    }
    printf("\n");
  }
  return 0;
}