#include <stdio.h>

int main()
{
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);

  (age >= 18) ? printf("Can Vote.") : printf("Can Not Vote."); 

  return 0;
}