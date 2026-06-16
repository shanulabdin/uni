#include <stdio.h>

int power(int x, int y){
  if(x == 0 || y == 0){
    return 1;
  }
  printf("\n%d", x);
  return x * power(x, y-1);
}

int main(){
  printf("\n%d", power(5, 5));

  return 0;
}