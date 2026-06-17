#include <stdio.h>

int main(){
  char str[100], rev[100];
  int length = 0, i;

  printf("Enter a string: ");
  scanf("%s", str); 
  printf("Original: %s", str);

  while(str[length] != '\0'){
    length++;
  }

  for(i = 0; i<length; i++){
    rev[i] = str[length - i - 1];
  }

  printf("\nReversed: %s", rev);


  return 0;
}