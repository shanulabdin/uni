#include <stdio.h>

int main()
{
  int i = 0;
  int array[] = {01, 12, 21, 32, 45, 56, 67, 78, 89, 90};

  while (i <= 9)
  {
    printf("array[%d]: %d \n", i, array[i]);
    i++;
  }

  return 0;
}
