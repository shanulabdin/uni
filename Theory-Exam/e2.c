#include <stdio.h>

int revInt(int num);

int main(){
  int num, rev;

  printf("Enter a number: ");
  scanf("%d", &num);

  rev = revInt(num);

  printf("Reverse = %d", rev);

  return 0;
}

int revInt(int num){
  int rev = 0, digits;

  while(num > 0){
    digits = num % 10;
    rev = rev * 10 + digits;
    num = num / 10;
  }
  return rev;
}