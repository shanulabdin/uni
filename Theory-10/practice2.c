#include <stdio.h>

int main(){
  int arr[6] = {4, 17, 2, 9, 31, 8};

  int max = arr[0];

  for(int i=0; i<6; i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  
  printf("Max = %d", max);
  return 0;
}