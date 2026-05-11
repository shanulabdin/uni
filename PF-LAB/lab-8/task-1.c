#include <stdio.h>

int main()
{
  int temp[7] = {34, 32, 33, 35, 34, 33, 35};
  int sum=0, average=0, hi=0, lo=temp[0]; 

  for(int i = 0; i<7; i++){
    sum = sum+temp[i];

    if(temp[i] > hi){
      hi=temp[i];
    }
    if(temp[i] < lo){
      lo=temp[i];
    }
  }

  average = sum / 7;
  printf("\nLowest Teperature: %d", lo);
  printf("\nHighest Teperature: %d", hi);
  printf("\nAverage Temperature: %d", average);
  
  return 0;
}
// 1.	Write a C program to store the temperatures recorded over 7 days in an array. Calculate and display the average temperature of the week. Also, find and display the highest and lowest temperatures recorded.