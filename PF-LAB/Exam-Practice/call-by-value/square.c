#include <stdio.h>

int square(int num) {
  return num * num;
}

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);
  
  printf("Square: %d", square(num));

  return 0;
}