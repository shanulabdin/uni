#include <stdio.h>

int main()
{
  int num, temp, digitCount = 0, sum = 0, product = 1;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 0)
    num = -num;
  temp = num;

  if (num == 0)
  {
    digitCount = 1;
    product = 0;
  }
  else
  {
    while (temp != 0)
    {
      int digit = temp % 10;
      digitCount++;
      sum += digit;
      product *= digit;
      temp /= 10;
    }
  }

  printf("Number of digits = %d\n", digitCount);
  printf("Sum of digits = %d\n", sum);
  printf("Product of digits = %d\n", product);

  return 0;
}
