#include <stdio.h>

int main(){
  int arr1[100] = {};
  int len = 0;

  printf("How many numbers do you want to enter? No: ");
  scanf("%d", &len);
  
  for(int i=0; i<len; i++){
    printf("Enter Number %d: ", i+1);
    scanf("%d", &arr1[i]);
  }

  printf("\nArray Elements Reversed: ");
  for(int i=len-1; i>=0; i--){
    printf("%d ", arr1[i]);
  }
  return 0;
}

// 2.	Write a C program that takes an array of integers as input and outputs the array in reverse order. The program should work for arrays of any size up to 100 elements.