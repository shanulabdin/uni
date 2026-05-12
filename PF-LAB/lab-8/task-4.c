#include <stdio.h>

int main()
{
  int temp[7];
  int sum=0, average=0, hi=0, lo=temp[0]; 

  for(int i=0; i<7; i++){
    printf("Enter temperature for day %d: ", i+1);
    scanf("%d", &temp[i]);
  }

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
  printf("Average Temperature of the Week: %d", average);
  
  return 0;
}

// 1: Write program to record the temperatures (in Celsius) for a week (7 days). Store these temperatures in an array and then calculate and display the average temperature for the week