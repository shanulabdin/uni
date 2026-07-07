#include <stdio.h>

void swap(int *x, int *y);

int main()
{
  int a, b;

  printf("Enter the value of a and b: ");
  scanf("%d %d", &a, &b);

  printf("\nBefore swap a: %d, b: %d", a, b);

  swap(&a, &b);

  printf("\nAfter swap a: %d, b: %d", a, b);

  return 0;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}