#include <stdio.h>

int main()
{
  int arr[5] = {5, 2, 7, 1, 4};
  int max = 0;

  for (int i = 0; i < 5; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return 0;
}
