#include <stdio.h>

int main()
{
  int a, b;

  printf("Enter 1st Number: ");
  scanf("%d", &a);

  printf("Enter 2nd Number: ");
  scanf("%d", &b);

  printf("%d is %s and %d is %s\n", a, (a %2==0)? "Even":"Odd", b, (b %2==0)?"Even":"Odd");

  return 0;
}