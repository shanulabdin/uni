#include <stdio.h>

int main()
{
  int a = 34, b=25;

  printf(a > b ? "A is greater." : "B is greater.");
  (a>b) ? printf("A is greater.") : printf("B is greater");

  return 0;
}