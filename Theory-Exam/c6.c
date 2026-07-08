#include <stdio.h>

int main(){
  FILE *fp;
  fp = fopen("data.txt", "w");

  int num, i;

  if(fp == NULL){
    printf("Error opening file.");
    return 1;
  }

  for(i = 0; i<5; i++){
    printf("Enter number %d: ", i+1);
    scanf("%d", &num);
    fprintf(fp, "%d\n", num);
  }

  fclose(fp);

  return 0;
}