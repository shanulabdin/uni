#include <stdio.h>

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main(){
  int x=6, y=7;

  printf("original: %d %d", x, y);
  swap(&x, &y);
  printf("\nswaped: %d %d", x, y);

  return 0;
}