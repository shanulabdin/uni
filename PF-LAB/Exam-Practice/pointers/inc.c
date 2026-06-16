#include <stdio.h>

void inc(int *var){
  *var = *var + 1;
}

int main(){
  int var = 5;

  printf("original: %d", var);
  inc(&var);
  printf("\nIncreased: %d", var);
  return 0;
}