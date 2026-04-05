#include <stdio.h>

int main()
{
  char pass[6] = "hello";
  char input[20];

  printf("Enter your password: ");
  scanf("%s", &input);

  if (strcmp(input, pass) == 0)
  {
    printf("Correct Password.");
  }
  else
  {
    printf("InCorrect Password.");
  }

  return 0;
}