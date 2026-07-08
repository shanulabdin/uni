#include <stdio.h>

int fact(int num);

int main(){
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);
  int res = fact(num);

  printf("Result: %d", res);

  return 0;
}

int fact(int num){
  int fa = 1;

  for(int i = num; i>0; i--){
    fa = fa * i;
  }

  return fa;
}