#include <stdio.h>

int main(){
  char ch;
  char *p = &ch;
  
  int words = 1, characters = 0;

  printf("Enter a sentence: ");
  
  while(1){
    scanf("%c", p);

    if(*p == '.'){
      break;
    }
    if(*p != ' '){
      characters++;
    }else{
      words++;
    }
  }
  printf("Words: %d ", words);
  printf("Characters: %d", characters);
  
  return 0;
}