#include <stdio.h>

int main()
{
  int n, raise, sum = 0;

  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    raise = i * i;
    sum = sum + raise;
    if (i < n)
      printf("%d^2 + ", i);
    else
      printf("%d^2", i);
  }

  printf(" = %d", sum);

  return 0;
}
