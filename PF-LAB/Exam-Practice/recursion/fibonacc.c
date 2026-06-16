#include <stdio.h>

int fibonnacci(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  else
  {
    printf("%d, ", n);

    return fibonnacci(n - 1) + fibonnacci(n - 2);
  }
}

int main()
{
  int fib = 0, num;

  printf("Enter the number: ");
  scanf("%d", &num);
  fib = fibonnacci(num);

  printf("\nFibonnacci: %d", fib);

  return 0;
}