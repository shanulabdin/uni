#include <stdio.h>
// If a four-digit number is input through the keyboard, write a program to obtain the sum of the first and last digit of this number.
int main()
{
  int num, first, last, sum = 0;

  printf("Enter 4 digit number: ");
  scanf("%d", &num);

  if (num >= 1000 && num < 9999)
  {
    first = num / 1000;
    last = num % 10;
    sum = first + last;

    printf("Sum of %d and %d is: %d.", first, last, sum);
  }
  else
  {
    printf("Please Enter a valid number.");
  }

  return 0;
}