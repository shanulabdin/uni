#include <stdio.h>

void rev(char *str){
  if(*str == '\0'){
    return;
  }

  rev(str + 1); 
  printf("%c", *str);  
}

int main(){
  char str[] = "Hello"; 
  printf("Original: %s", str);
  printf("\nReversed: ");

  rev(str);

  return 0;
}