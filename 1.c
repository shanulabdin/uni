#include <stdio.h>

int function(int d){
  int r = 4 + d;
  return r;
}

int main(){
  int a = 10;

  printf("\nThe result is %d", function(a));

  return 0;
}