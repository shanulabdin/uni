#include <stdio.h>

int main()
{
  int arr[5] = {5, 2, 7, 1, 4};
  int f = 7;

  for (int i = 0; i < 5; i++)
  {
    if (arr[i] == f){
      printf("The number %d was at address: arr[%d]", f, i);
    }
  }
  return 0;
}
