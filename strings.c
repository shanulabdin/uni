#include <stdio.h>

char* string(){
  char* str = "This is a String!";
  return str;
}

int number(){
  int num = 10;
  return num;
}

int main(){
  char* str = string();
  int num = number();

  printf("%s\n", str);
  printf("This is an integer: %d\n", num);

  return 0;
}