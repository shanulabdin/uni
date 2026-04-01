#include <stdio.h>

int main()
{
  int i, num=0, sum = 0;
  for (i = 1; i <= 10; i++)
  {
    printf("Enter a number: ");
    scanf("%d", &num);

    sum = sum + num;
    printf("Current sum: %d\n", sum);
  }
  printf("Final sum: %d\n", sum);
  return 0;
}