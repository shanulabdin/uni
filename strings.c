#include <stdio.h>

char* string(){
  char* str = "Hello World!";
  return str;
}

int main(){
  char* str;
  str = string();
  
  printf("%s\n", str);
  printf("%s", str); 

  return 0;
}