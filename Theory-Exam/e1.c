#include <stdio.h>

int countDig(int num);

int main(){
  int num, count;

  printf("Enter a number: ");
  scanf("%d", &num);

  count = countDig(num);

  printf("Digits = %d", count);

  return 0;
}

int countDig(int num){
  int count = 0;

  if(num == 0) return 1;
  if(num < 0) num = -num;
  
  while(num > 0){
    count++;
    num = num / 10;
  }
  return count;
}