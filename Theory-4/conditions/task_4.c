#include <stdio.h>

int main()
{
  int a = 6, b = 10;
  switch (a < 7 && b > 9)
  {
  case 1:
    printf("Condition is TRUE");
    break;
  case 0:
    printf("Condition is FALSE");
    break;
  }

  return 0;
}