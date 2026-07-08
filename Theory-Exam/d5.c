#include <stdio.h>

int main(){
  int arr[3][3], i, j, rowsum, colsum;

  
  printf("Enter the elements: ");
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  printf("Matrix: \n");
  for(i=0; i<3; i++){
    rowsum = 0;
    for(j=0; j<3; j++){
      printf("%d ", arr[i][j]);
      rowsum += arr[i][j];
    }
    printf(" Rowsum: %d ", rowsum);
    printf("\n");
  }

  for(i=0; i<3; i++){
    colsum = 0;
    for(j=0; j<3; j++){
      colsum += arr[j][i];
    }
    printf(" Colsum [%d]: %d ",i, colsum);
    printf("\n");
  }

  return 0;
}