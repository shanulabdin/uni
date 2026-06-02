#include <stdio.h>

int main()
{
  int arr[3][3] = {{3, 7, 2}, {8, 9, 5}, {4, 9, 6}};
  int find = 9;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] == find)
      {
        printf("Element is on arr[%d][%d]\n", i, j);
      }
    }
  }

  return 0;
}