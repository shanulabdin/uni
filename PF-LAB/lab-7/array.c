#include <stdio.h>

int main()
{
  int array[4];

  array[0] = 01;
  array[1] = 12;
  array[2] = 21;
  array[3] = 32;

  for (int i = 0; i <= 3; i++)
  {
    printf("array[%d]: %d \n", i, array[i]);
  }

  return 0;
}