#include <stdio.h>
int main()
{
  int x = 30, y = 25, z = 20, w = 10;
  printf("%d", (x * y) / z - w);
  printf("%d", w - (x * y) / z);

  return 0;
}