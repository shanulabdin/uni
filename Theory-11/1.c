#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "Shan";
  char str2[20] = "Pathan";
  char str3[20];
  
  printf("Lowercase letters: %s\n", strlwr(str1));
  printf("Uppercase letters: %s\n", strupr(str2));
  
  strcpy(str3, str1);
  printf("The copied string is: %s\n", str3);
  
  strcat(str1,"");
  strcat(str1,str2);
  printf("The combined string is: %s", str1);

  return 0;
}