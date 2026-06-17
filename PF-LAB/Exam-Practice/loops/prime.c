#include <stdio.h>

int main()
{
  int num = 73;
  int isprime = 1;

  for(int i=2;i*i<=num;i++)
  {
    if (num % i==0){
      isprime = 0;
      break;
    }
  }

    if (isprime == 1){
      printf("Prime");
    } else {
      printf("Not Prime");
    }
  return 0;
}
