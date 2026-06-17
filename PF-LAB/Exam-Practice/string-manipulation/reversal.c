#include <stdio.h>

void rev(char *str){
  if(*str == '\0'){
    return;
  }

  rev(str + 1); 
  printf("%c", *str);  
}

int main(){
  char str[100];
  scanf("%s", str); 
  printf("Original: %s", str);
  printf("\nReversed: ");

  rev(str);

  return 0;
}