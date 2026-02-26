#include <stdio.h>

int function(){
  return 4;
}

int main(){
  int a, b, c, d;
  a= 16;
  b= 8;
  c= a - b;
  d= c + 8;

  printf("The result is %d", d); // 16
  
  int f =  function(d);
  
  int r = f + d;
  printf("\nThe result is %d", r); // 16

  return 0;
}