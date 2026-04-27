// 1.	Write a C program to store the temperatures recorded over 7 days in an array. Calculate and display the average temperature of the week. Also, find and display the highest and lowest temperatures recorded.
#include <stdio.h>

int main()
{
  int temp[] = {98, 99, 100, 99, 98, 97};

  for (int i = 0; i <= 5; i++)
  {
    printf("%d ",temp[i]);
  }

  return 0;
}