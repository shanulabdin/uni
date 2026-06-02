#include <stdio.h>

int largest_of(int, int, int);

int main()
{
  int a, b, c, largest;

  printf("Enter 3 Numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  largest = largest_of(a, b, c);

  printf("%d is largest.\n", largest);

  return 0;
}

int largest_of(int a, int b, int c)
{
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