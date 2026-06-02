#include <stdio.h>

int main(){
  int arr[2][4] = {{1,2,3,4},{5,6,7,8}};

  int sum = 0;

  for(int i=0; i<2; i++){
    for(int j=0; j<4; j++){
      sum = sum + arr[i][j];
    }
  }
  printf("%d ", sum);

  return 0;
}