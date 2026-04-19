#include <stdio.h>

int main()
{
  int num, original, temp, digits = 0, sum = 0;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 0)
  {
    printf("%d is not an Armstrong number.\n", num);
    return 0;
  }

  original = temp = num;
  while (temp)
  {
    digits++;
    temp /= 10;
  }
  if (digits == 0)
    digits = 1;

  temp = num;
  while (temp)
  {
    int digit = temp % 10;
    int power = 1;
    int i = digits;

    while (i--)
    {
      power *= digit;
    }

    sum += power;
    temp /= 10;
  }

  if (num == 0)
    sum = 0;

  if (sum == original)
  {
    printf("%d is an Armstrong number.\n", original);
  }
  else
  {
    printf("%d is not an Armstrong number.\n", original);
  }

  return 0;
}