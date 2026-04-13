#include <stdio.h>

int main()
{
  int count = 0, num;

  for (int i = 0; i <= 99; i++)
  {
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num != 0)
    {
      count++;
    }
    else
    {
      break;
    }
  }

  printf("Total count of numbers entered: %d", count);
  return 0;
}