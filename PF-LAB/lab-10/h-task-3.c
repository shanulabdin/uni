#include <stdio.h>

int power(int x, int y)
{
  if (y == 0)
    return 1;

  printf("\nStack Rolling: x = %d, y = %d", x, y);
  int result = x * power(x, y - 1);
  printf("\nStack Unrolling: result = %d", result);

  return result;
}

int main()
{
  int x, y;

  printf("Enter base (x): ");
  scanf("%d", &x);

  printf("Enter power (y): ");
  scanf("%d", &y);

  int result = power(x, y);

  printf("\nResult: %d\n", result);

  return 0;
}