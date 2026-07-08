#include <stdio.h>
#include <string.h>

int main(){
  char user[20], pass[20];

  printf("Enter username: ");
  scanf("%s", &user);

  printf("Enter password: ");
  scanf("%s", &pass);
  
  for(int i = 0; user[i] != '\0'; i++){
    user[i] = tolower(user[i]);
  }
  
  if(strcmp(user, "admin") == 0 && strcmp(pass, "Exam2026") == 0){
    printf("Access granted.");
  }else{
    printf("Incorrect username or password.");
  }
  return 0;
}