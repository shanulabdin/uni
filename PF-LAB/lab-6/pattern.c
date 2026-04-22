#include <stdio.h>

int main()
{
  for(int i = 1; i<10; i=i+)
  {
    for(int j = 0; j < i; j++){
      printf(" ");
    }
    for(int k = 9; k >= i; k--){
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}