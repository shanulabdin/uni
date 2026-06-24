#include <stdio.h>

int main()
{
  float area, length, width;

  printf("Enter the length of the Rectangle: ");
  scanf("%f", &length);

  printf("Enter the width of the Rectangle: ");
  scanf("%f", &width);

  area = length * width;

  printf("Area of the Rectangle is: %.2f", area);

  return 0;
}