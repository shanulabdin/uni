#include <stdio.h>

int main()
{
  int arr[10];
  int a, i, temp;

  printf("Enter number of elemensts: ");
  scanf("%d", &a);

  for(i = 0; i < a; i++)
  {
    printf("Enter arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  int j = a-1;
  for(i = 0; i<j; i++){
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    j--;
  }

  for(i = 0; i < a; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}