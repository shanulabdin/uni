#include <stdio.h>

int sumDigits(int num);

int main()
{
  int num = 0;
  printf("Enter an integer: ");
  scanf("%d", &num);

  printf("Sum of digits: %d", sumDigits(num));

  return 0;
}
int sumDigits(int num){
  int sum = 0;

  if(num < 0)
    num = -num;

  while(num > 0){
    sum = sum + (num % 10);
    num = num / 10;
  }

  return sum;
}