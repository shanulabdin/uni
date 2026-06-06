#include <stdio.h>

int getLsd(int);
int getMsd(int);

int main(){
  int num, lsd, msd;
  printf("Enter a 3 digit number: ");
  scanf("%d", &num);
  
  lsd = getLsd(num);
  msd = getMsd(num);
  
  printf("Least Significant Digit: %d \n", lsd);
  printf("Most Significant Digit: %d ", msd);

  return 0;
}

int getLsd(int num){
  int lsd = num % 10;
  
  return lsd;
}

int getMsd(int num){
  int msd = num / 100;

  return msd;
}