#include <stdio.h>

char* string(){
  return "hello";
}

int main(){
  char str[4] = "meow";
  printf("%s\n", str);
  printf("%s\n", string());

  return 0;
}