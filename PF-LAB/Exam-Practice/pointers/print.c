#include <stdio.h>

int main()
{
  int x = 7;
  int *p = &x;

  *p = 20;

  printf("%d", x);
  return 0;
}