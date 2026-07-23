#include <stdio.h>
#include <string.h>

void vowCon(char str[]);

int main()
{
  char str[50];

  printf("Enter a string: ");
  scanf("%s", str);

  vowCon(str);
}

void vowCon(char str[])
{
  int vowels = 0, consonents = 0;

  for (int i = 0; i < strlen(str); i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
    {
      vowels++;
    }
    else
    {
      consonents++;
    }
  }
  printf("\nVowels: %d", vowels);
  printf("\nConsonents: %d", consonents);
}