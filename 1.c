#include <stdio.h>

int function(int d){
  int r = 4 + d;
  return r;
}

int main(){
  int a, b, c, d;
  a= 16;
  b= 8;
  c= a - b;
  d= c + 8;

  printf("The result is %d", d); // 16
  
  int f =  function(d);
  
  printf("\nThe result is %d", f); // 16

  return 0;
}