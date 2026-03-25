// Online C compiler to run C program online
#include <stdio.h>

int main()
{
  // Write C code here
  printf("This is my First C program\n");

  // data types in C
  int w, x = 12;
  float y = 4.332;
  char z = 'a';

  // Format Specifiers "Escape sequences"

  printf("my integer variable is x= %d \n", x);
  printf("my float variable is y= %f \n", y);
  printf("my character variable is z= %c \n", z);

  // to get user input.
  printf("enter an integer value ");
  scanf("%d", &w);
  printf("you entered w= %d", w);

  return 0;
}