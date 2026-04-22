#include <stdio.h>

int main()
{
  int array[] = {01, 12, 21, 32, 45, 56, 67, 78, 89, 90};
  int size = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < size; i++)
  {
    printf("array[%d]: %d \n", i, array[i]);
  }

  return 0;
}
