#include <stdio.h>

int main()
{
  int n, i, x;
  int largest, secondLargest;

  printf("Enter how many numbers: ");
  scanf("%d", &n);

  if (n < 2)
  {
    printf("Need at least 2 numbers.\n");
    return 0;
  }

  printf("Enter number 1: ");
  scanf("%d", &largest);
  printf("Enter number 2: ");
  scanf("%d", &secondLargest);

  if (secondLargest > largest)
  {
    int temp = largest;
    largest = secondLargest;
    secondLargest = temp;
  }

  i = 3;
  while (i <= n)
  {
    printf("Enter number %d: ", i);
    scanf("%d", &x);

    if (x > largest)
    {
      secondLargest = largest;
      largest = x;
    }
    else if (x > secondLargest)
    {
      secondLargest = x;
    }

    i++;
  }

  printf("Second largest number = %d\n", secondLargest);

  return 0;
}
