#include <stdio.h>

int largest_of();

int main()
{
  int largest = largest_of();

  printf("%d is largest.\n", largest);

  return 0;
}

int largest_of()
{
  int a, b, c;

  printf("Enter 3 Numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  if (a >= b && a >= c)
  {
    return a;
  }
  else if (b >= a && b >= c)
  {
    return b;
  }
  else
  {
    return c;
  }
}