#include <stdio.h>
#include <string.h>

int countStr(char str[]);

int main()
{
  char str[50];
  int count = 0;

  printf("Enter the string: ");
  scanf("%s", str);

  count = countStr(str);
  printf("Count = %d", count);

  return 0;
}

int countStr(char str[]){
  int words = 1;
  int i = 0;

  while(str[i] != '\0'){
    if(str[i] == ' '){
      words++;
    }
    i++;
  }

  return words;
}