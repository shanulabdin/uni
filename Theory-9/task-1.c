#include <stdio.h>

void largest_of();

int main()
{
  largest_of();

  return 0;
}

void largest_of()
{
  int a, b, c;

  printf("Enter 3 Numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  if (a >= b && a >= c)
  {
    printf("%d is largest.\n", a);
  }
  else if (b >= a && b >= c)
  {
    printf("%d is largest.\n", b);
  }
  else
  {
    printf("%d is largest.\n", c);
  }
}