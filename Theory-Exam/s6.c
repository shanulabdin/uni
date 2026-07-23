#include <stdio.h>
#include <string.h>

int main()
{
  char ch;
  char *p = &ch;

  int count = 1;
  
  printf("Enter the string: ");
  
  while(1){
    scanf("%c", p);

    if(*p == '.'){
      break;
    }
    if(*p == ' '){
      count++;
    }
  }

  printf("Count = %d", count);

  return 0;
}
