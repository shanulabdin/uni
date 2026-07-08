#include <stdio.h>

void isPrime(int num);

int main()
{
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  isPrime(num);

  return 0;
}

void isPrime(int num)
{
  if(num <= 1){
    printf("NOT Prime");
    return;
  }
  for (int i = 2; i < num; i++)
  {
    if(num % i == 0){
      printf("NOT Prime");
      return;
    }
  }
  printf("Prime");
}