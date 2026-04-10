#include <stdio.h>

int main()
{
  int i = 1, password = 2026, user = 0;

  while (user != password && i <= 5)
  {
    printf("\nEnter your password: ");
    scanf("%d", &user);

    if (user == password)
    {
      printf("Correct Password.");
    }
    else
    {
      printf("InCorrect Password.");
    }

    i++;
  }

  return 0;
}