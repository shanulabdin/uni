#include <stdio.h>

int function(int d){
  int r = 4 + d;
  printf("\nThe result is %d", r); // 20
}

int main(){
  int a = 10;

  function(a);

  return 0;
}