#include <stdio.h>
#include <string.h> 

int main()
{
  char pass[6] = "hello";
  char input[20];

  while (1) 
  {
    printf("Enter your password: ");
    scanf("%s", input);

    if (strcmp(input, pass) == 0)
    {
      printf("Correct Password.\n");
      break;
    }
    else
    {
      printf("Incorrect Password. Try again.\n");
    }
  }

  return 0;
}