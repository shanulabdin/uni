#include <stdio.h>

int main()
{
  int choice;

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1: printf("The Choice is 1");
      break;
    case 2: printf("The Choice is 2");
      break;
    case 3: printf("The Choice is 3");
      break;
    default: printf("Not matched value.");
  }

  return 0;
}