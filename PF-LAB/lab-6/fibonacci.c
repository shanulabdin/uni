#include <stdio.h>

int main()
{
  int num, a = 0, b = 1, next;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num > 0)
  {
    printf("Fibonacci series: ");

    for (int i = 1; i <= num; i++)
    {
      printf("%d ", a);
      next = a + b;
      a = b;
      b = next;
    }
  }
  else
  {
    printf("Please enter a positive number.");
  }
  return 0;
}