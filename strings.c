#include <stdio.h>

char* string(){
  char* str = "This is a String!";
  return str;
}

int main(){
  char* str = string();
  
  printf("%s", str); 

  return 0;
}