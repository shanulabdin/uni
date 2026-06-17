#include <stdio.h>

int main(){
  char str[100] = "helLo";
  int i = 0;

  while(str[i] != '\0'){
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }

  i++;
  }

  printf("%s", str);
  return 0;
}