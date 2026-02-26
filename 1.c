#include <stdio.h>

int function(int d){
  int r = 4 + d;
  printf("\nThe result is %d", r); // 20
}

int main(){
  int a, b, c, d;
  a= 16;
  b= 8;
  c= a - b;
  d= c + 8;

  function(d);

  return 0;
}