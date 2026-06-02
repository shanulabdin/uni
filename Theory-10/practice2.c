#include <stdio.h>

int main(){
  int arr[8] = {3, 8, 5, 12, 7, 6, 1, 4};

  for(int i=0; i<8; i++){
    if(arr[i] %2== 0){
      printf("%d ", arr[i]);
    }
  }
  return 0;
}