#include <stdio.h>

int main()
{
  int arr[3][3] = {{1, -2, 0}, {-4, 5, 6}, {0, -1, 3}};
  int positive = 0, negative = 0, zero = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] > 0)
      {
        positive++;
      }
      else if (arr[i][j] < 0)
      {
        negative++;
      }
      else
      {
        zero++;
      }
    }
  }

  printf("Positive = %d\nNegative = %d\nZero = %d", positive, negative, zero);
  return 0;
}