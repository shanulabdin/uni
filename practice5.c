#include <stdio.h>

int sumArray(int arr[], int size){
  int sum = 0;
  for(int i=0; i<size; i++){
    sum = sum + arr[i];
  }
  return sum;
}

int main()
{
  int arr[5] = {2, 4, 6, 8, 10};
  int sum = sumArray(arr, 5);

  printf("Total = %d\n", sum);
  return 0;
}