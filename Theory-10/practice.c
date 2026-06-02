#include <stdio.h>
int findMax(int a, int b)
{
  if(a>b){
    printf("Max = %d\n", a);
  }else{
    printf("Max = %d\n", b);
  }
}
int main()
{
  findMax(12,7);
  findMax(3,9);
  return 0;
}