#include <stdio.h>

int main(){
  FILE *fp;
  fp = fopen("msg.txt", "a");

  if(fp == NULL){
    printf("Error opening file.");
    return 1;
  }

  fprintf(fp, "Exam tomorrow!");

  fclose(fp);

  return 0;
}