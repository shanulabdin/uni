#include <stdio.h>

int main()
{
  int len = 0, temp;
  int arr1[100];

  printf("How many numbers do you want to enter? max 100. No: ");
  scanf("%d", &len);

  for (int i = 0; i < len; i++)
  {
    printf("Enter Number %d: ", i + 1);
    scanf("%d", &arr1[i]);
  }

  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - 1; j++)
    {
      if (arr1[j] < arr1[j + 1])
      {
        temp = arr1[j];
        arr1[j] = arr1[j + 1];
        arr1[j + 1] = temp;
      }
    }
  }

  printf("\nSorted Array in descending order:\n");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr1[i]);
  }

  return 0;
}

// Write a C program that takes an array of integers and its size as inputs, and sorts the array in descending order using the Bubble Sort algorithm. Display the sorted array in the main function