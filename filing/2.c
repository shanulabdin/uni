#include <stdio.h>

int main(){
  char message[99];
  FILE *fp;
  fp = fopen("message.txt", "w");

  fputs("Good Luck for Quiz!", fp);

  fclose(fp);

  return 0;
}