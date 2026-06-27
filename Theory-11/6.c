#include <stdio.h>

int main()
{

  int myArray[5] = {2, 4, 6, 8, 10};
  int otherArray[5] = {0, 0, 0, 0, 0};

  for (int i = 0; i < 4; i++)
  {
    otherArray[i] = myArray[i] * myArray[i];
    printf("Product : %d\n", otherArray[i]);
  }

  printf("otherarray: ");
  for (int i = 0; i < 4; i++)
  {
    printf("%d ", otherArray[i]);
  }

  return 0;
}