#include <stdio.h>

int factorial(int num);

int main(){
  int num = 4;
  int res = factorial(num);
  printf("Res: %d", res);
  return 0;
}

int factorial(int num){
  int fac = 1;

  for(int i=num; i>0; i--){
    fac = fac * i;
  }
  return fac;
}