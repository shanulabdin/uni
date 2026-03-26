#include <stdio.h>

int main()
{
  double var1;

  printf("Enter your salary: \t");
  scanf("%lf", &var1);

  if (var1 > 100000)
  {
    printf("It's a fine package.");
  }
  else
  {
    printf("Search more.");
  }

  return 0;
}