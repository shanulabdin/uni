#include <stdio.h>

int main(){
  FILE *fp;
  fp = fopen("data.txt", "r");

  if(fp == NULL){
    printf("Error opening file.");
    return 1;
  }

  int sum = 0, num, i;
  while(fscanf(fp, "%d", &num) != EOF){
    sum += num;
  }

  printf("%d", sum);
  
  return 0;
}