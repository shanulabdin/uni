#include <stdio.h>
#include <string.h>

int main()
{
  char str[100], rev[100];
  int length = 0, i = 0, vowels = 0;

  printf("Enter a string: ");
  scanf("%s", str);

  while (str[length] != '\0')
  {
    length++;
  }

  int palindrome = 1;

  for (i = 0; i < length; i++)
  {
    if (str[i] != str[length - i - 1])
    {
      palindrome = 0;
      break;
    }
  }

  if (palindrome)
  {
    printf("Palindrome");
  }
  else
  {
    printf("Not palindrome");
  }

  return 0;
}