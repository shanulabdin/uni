#include <stdio.h>

int main()
{
  int arr[3][4] =  {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int sum;
  for (int i=0; i < 3; i++)
  {
    sum = 0;
    for(int j=0; j<4; j++){
      sum = sum + arr[i][j];  
    }
    printf("Row %d Sum = %d\n", i, sum);
  }

  return 0;
}