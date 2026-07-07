#include <stdio.h>
#include <conio.h>

void main()
{
  int count = 0;

  clrscr();

  printf("Type a phrase: ");

  while (getchar() != '\r')
    count++;

  printf("\nCharacter count is %d", count);

  getch();
}