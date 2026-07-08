#include <stdio.h>
#include <ctype.h>

int main(){
  char ch;
  char *p = &ch;
  int vowels = 0, digits = 0;

  printf("Enter a sentence ending with '#': ");

  while(1){
    scanf("%c", p);
    if(*p == '#'){
      break;
    }

    if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
    *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U'){
      vowels++;
    }
    if(isdigit(*p)){
      digits++;
    }
  }

  printf("Vowels: %d\n", vowels);
  printf("Digits: %d", digits);

  return 0;
}