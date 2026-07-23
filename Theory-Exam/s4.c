#include <stdio.h>
#include <string.h>

int main()
{
  char str1[50], str2[50];
  int i, j, temp;

  printf("Enter the 1st string: ");
  scanf("%s", str1);

  printf("Enter athe 2nd string: ");
  scanf("%s", str2);

  if(strlen(str1) != strlen(str2)){
    printf("Not Anagram.");
    return 0;
  }

  for(i = 0; i<strlen(str1)-1; i++){
    for(j = 0; j<strlen(str1)-1; j++){
      if(str1[j] > str1[j + 1]){
        temp = str1[j];
        str1[j] = str1[j+1];
        str1[j+1] = temp;
      }
    }
  }

  for(i = 0; i < strlen(str2)-1; i++){
    for(j=0; j<strlen(str2)-1; j++){
      if(str2[j] > str2[j+1]){
        temp = str2[j];
        str2[j] = str2[j+1];
        str2[j+1] = temp;
      }
    }
  }

  printf("\nstring 1: ");
  for(int i = 0; i<strlen(str1); i++){
    printf("%c ", str1[i]);
  } 
  printf("\nstring 2: ");
  for(int i = 0; i<strlen(str2); i++){
    printf("%c ", str2[i]);
  } 

  if(strcmp(str1, str2) != 0){
    printf("\nNot Anagram.");
  }else{
    printf("\nAnagram.");
  }
  return 0;
}