#include <stdio.h>

int main()
{
  int num = 0;

  do
  {
    printf("Enter any number, (-ve numbers to stop): ");
    scanf("%d", &num);
  } while (num >= 0);

  printf("Program ended, negetive number entered: %d", num);

  return 0;
}