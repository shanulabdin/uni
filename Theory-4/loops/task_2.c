#include <stdio.h>

int main()
{
  int i, prod, num;
  printf("Enter the number you want the table for: ");
  scanf(" %d", &num);

  for (i = 1; i <= 10; i++)
  {
    prod = num * i;
    printf("%d * %d = %d\n", num, i, prod);
  }
  return 0;
}