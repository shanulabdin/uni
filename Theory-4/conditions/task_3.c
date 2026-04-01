#include <stdio.h>

int main()
{
  char oper;
  float num1, num2, res;

  printf("Enter the Numbers: ");
  scanf("%f %f", &num1, &num2);

  printf("Enter the Operator +, -, /, *: ");
  scanf(" %c", &oper);

  switch (oper)
  {
  case '+':
    res = num1 + num2;
    printf("The sum of %0.2f and %0.2f is: %0.2f", num1, num2, res);
    break;
  case '-':
    res = num1 - num2;
    printf("The difference of %0.2f and %0.2f is: %0.2f", num1, num2, res);
    break;
  case '/':
    res = num1 / num2;
    printf("The division of %0.2f and %0.2f is: %0.2f", num1, num2, res);
    break;
  case '*':
    res = num1 * num2;
    printf("The Product of %0.2f and %0.2f is: %0.2f", num1, num2, res);
    break;
  default:
    printf("Invalid Input.");
  }

 return 0;
}