#include <stdio.h>

int main()
{
  for (int i = 1; i <= 5; i++)
  {
    printf("hello %d \n", i);

    for (int j = 1; j <= 3; j++)
    {
      printf("   nested %d \n", j);
    }
  }

  return 0;
}