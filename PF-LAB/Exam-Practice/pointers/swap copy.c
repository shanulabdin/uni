#include <stdio.h>

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main(){
  int a = 6, b = 7;
  int *x = &a;
  int *y = &b;

  printf("original: %d %d", *x, *y);
  swap(x, y);
  printf("\nswaped: %d %d", *x, *y);

  return 0;
}