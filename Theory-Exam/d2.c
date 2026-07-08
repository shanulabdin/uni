#include <stdio.h>

int main(){
  int arr[10], n, i, j, temp;

  printf("Enter n: ");
  scanf("%d", &n);

  printf("Enter elements: ");
  for(i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  for(i = 0; i<n; i++){
    for(j = 0; j<n-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("Sorted Ascending Array: ");
  for(i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

