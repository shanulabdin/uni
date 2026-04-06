#include <stdio.h>
#include <string.h> // Include for strcmp function

int main()
{
  char pass[6] = "hello";
  char input[20];

  while (1) // Infinite loop
  {
    printf("Enter your password: ");
    scanf("%s", input);

    if (strcmp(input, pass) == 0)
    {
      printf("Correct Password.\n");
      break; // Exit the loop when the password is correct
    }
    else
    {
      printf("Incorrect Password. Try again.\n");
    }
  }

  return 0;
}