#include <stdio.h>

char* string(){
  return "hello";
}

int main(){
  char* str;
  str = string();
  
  printf("%s\n", str);

  return 0;
}