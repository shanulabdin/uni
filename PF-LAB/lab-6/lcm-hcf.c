#include <stdio.h>
// 3.	Write a program to find GCD (greatest common divisor or HCF) and LCM (least common multiple) of two numbers
int main()
{
  int num1, num2, min, lcm = 0, hcf = 0;

  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter second number: ");
  scanf("%d", &num2);

  if (num1 < num2)
  {
    min = num1;
  }
  else
  {
    min = num2;
  }

  for (int i = 2; i <= min; i++)
  {
    if (num1 % i == 0 && num2 % i == 0)
    {
      hcf = i;
    }
  }

  lcm = num1 * num2 / hcf;
  printf("HCF: %d \n", hcf);
  printf("LCM: %d ", lcm);

  return 0;
}