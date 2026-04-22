#include <stdio.h>

int main()
{
  int num, original, temp, digitCount = 0, sum = 0;

  printf("Enter the number: ");
  scanf("%d", &num);

  if (num < 0)
  {
    printf("%d is not an Armstrong number.\n", num);
    return 0;
  }

  original = num;
  temp = num;

  if (temp == 0)
    digitCount = 1;

  while (temp != 0)
  {
    digitCount++;
    temp = temp / 10;
  }

  temp = num;

  while (temp != 0)
  {
    int remainder = temp % 10;
    int power = 1;
    int i = 0;

    while (i < digitCount)
    {
      power = power * remainder;
      i++;
    }

    sum = sum + power;
    temp = temp / 10;
  }

  if (num == 0)
    sum = 0;

  if (sum == original)
    printf("%d is an Armstrong number.\n", original);
  else
    printf("%d is not an Armstrong number.\n", original);

  return 0;
}