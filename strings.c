#include <stdio.h>

char* string(){
  char* str = "This is a String!";
  return str;
}

int number(){
  int num = 10;
  return num;
}

float decimal(){
  float dec = 3.14;
  return dec;
}

int main(){
  char* str = string();
  int num = number();
  float dec = decimal();

  printf("%s\n", str);
  printf("This is an integer: %d\n", num);
  printf("This is a float: %f\n", dec);

  return 0;
}