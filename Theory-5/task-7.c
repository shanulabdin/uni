#include <stdio.h>

int main()
{
  int num;
  printf("Enter a number, (0 to stop).\n");

  do
  {
    printf("Enter a number: ");
    scanf("%d", &num);
  } while (num != 0);

  printf("you entered 0.");

  return 0;
}