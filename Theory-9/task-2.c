#include <stdio.h>

void largest_of(int, int, int);

int main()
{
  int a, b, c;

  printf("Enter 3 Numbers: ");
  scanf("%d %d %d", &a, &b, &c);
  
  largest_of(a, b, c);

  return 0;
}

void largest_of(int a, int b, int c)
{
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