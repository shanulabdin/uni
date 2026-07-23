#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main()
{
  char str[50];

  printf("Enter a string: ");
  scanf("%s", str);

  reverse(str);
}

void reverse(char str[])
{
  int i = 0;
  int j = strlen(str) - 1;
  int len = strlen(str);
  char temp;

  while(i < j){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
  for(int i = 0; i<len; i++){
    printf("%c", str[i]);
  } 
}