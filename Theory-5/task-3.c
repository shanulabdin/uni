#include <stdio.h>

int main()
{
  int i = 1, num = 0, sum = 0;
  char ans = 'Y';

  while (i <= 10 && (ans == 'y' || ans == 'Y'))
  {
    printf("\nEnter a number: ");
    scanf("%d", &num);
    sum = num + sum;

    printf("Do you want to enter another number? Y/N: ");
    scanf(" %c", &ans);

    i++;

    printf("Sum = %d", sum);
  }

  return 0;
}