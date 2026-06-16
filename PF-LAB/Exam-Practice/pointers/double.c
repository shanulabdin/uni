#include <stdio.h>

void doubled(int *n){
  *n = *n * 2;
}

int main(){
  int n = 5;

  doubled(&n);
  printf("%d", n);

}