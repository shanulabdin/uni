#include <stdio.h>

int main(){
  FILE *fp;
  fp = fopen("data.txt", "r");

  if(fp == NULL){
    printf("Error opening file.");
    return 1;
  }

  int num;
  while(fscanf(fp, "%d", &num) != EOF){
    printf("%d ", num);
  }
  fclose(fp);

  return 0;
}