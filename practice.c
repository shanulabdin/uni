#include <stdio.h>

int main (){
  int a, b;
  
  printf("Enter 1st Number: ");
  scanf("%d", &a);

  printf("Enter 2nd Number: ");
  scanf("%d", &b);

  if(a %2==0 && b %2==0)
  {
    printf("%d, %d are both Even Numbers\n", a, b);
  } else if (a %2!=0 && b %2==0)
  {
    printf("%d is Odd and %d is Even\n", a, b);
  } else if (a %2==0 && b %2!=0)
  {
    printf("%d is Even and %d is Odd\n", a, b);
  } else {
    printf("%d, %d are both Odd Numbers\n", a, b);
  }

  return 0;
}