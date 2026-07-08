#include <stdio.h>
#include <string.h>

int palindrome(char str[]);

int main(){
  char str[50];

  printf("Enter a string: ");
  scanf("%s", str);

  if(palindrome(str)){
    printf("\nPalindrome.");
  }else{
    printf("\nNot Palindrome.");
  }
}

int palindrome(char str[]){
  int i = 0;
  int j = strlen(str) - 1;

  while(i < j){
    if(str[i] != str[j]){
      return 0;
    }

    i++;
    j--;
  }
  return 1;
}