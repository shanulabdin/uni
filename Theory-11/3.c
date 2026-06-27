#include <stdio.h>
int main()
{
  int i, j;
  for (i = 1; i <= 3; i++)

  {
    printf("\n");
    for (j = 1; j <= 4; j++)
    {
      printf("%d,%d  ", i, j);
    }
  }
  return 0;
}