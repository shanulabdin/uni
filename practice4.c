#include <stdio.h>

void calc(int a, int b){
  int sum, prod;
  sum = a+b;
  prod = a*b;

  printf("Sum = %d\n", sum);
  printf("Product = %d", prod);
}

int main()
{
  calc(2, 3);
  return 0;
}