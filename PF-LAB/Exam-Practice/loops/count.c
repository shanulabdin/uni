#include <stdio.h>

int main()
{
  int arr[5] = {5, 2, 7, 1, 4};
  int p = 0, n = 0;

  for (int i = 0; i < 5; i++)
  {
    if (arr[i] % 2 == 0){
      p++;
    }else{
      n++;
    }
  }
  printf("Positive: %d, Negetive: %d", p, n);
  return 0;
}
