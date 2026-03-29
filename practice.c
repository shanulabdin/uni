#include <stdio.h>

int main()
{
  int a, b;

  printf("Enter 1st Number: ");
  scanf("%d", &a);

  printf("Enter 2nd Number: ");
  scanf("%d", &b);

  if(a % 2 == 0)
  {
    if(b % 2 == 0){
      printf("%d and %d are both Even\n", a, b);
    } else {
      printf("%d is Even and %d is Odd\n", a, b);
    }
  } else
  {
    if(b % 2 == 0){
      printf("%d is Even and %d is Odd\n", b, a);
    } else {
      printf("%d and %d are both Odd\n", a, b);
    }
  }

  return 0;
}