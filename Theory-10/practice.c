#include <stdio.h>
int checkNumber(int num)
{
  if (num > 0)
  {
    printf("Positive\n");
  }
  else if (num == 0)
  {
    printf("Zero\n");
  }
  else
  {
    printf("Negetive\n");
  }
}
int main()
{
  checkNumber(5);
  checkNumber(-3);
  checkNumber(0);
  return 0;
}