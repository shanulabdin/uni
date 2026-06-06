#include <stdio.h>

int maxTemp(int tempArr[], int days);

int main()
{
  int days = 7;
  int tempArr[7] = {36, 34, 33, 35, 34, 37, 36};

  int day = maxTemp(tempArr, days);
  printf("The maximum temperature was recorded on day %d.", day);

  return 0;
}

int maxTemp(int tempArr[], int days)
{
  int max = tempArr[0];
  int maxDay = 0;

  for (int i = 1; i < days; i++)
  {
    if (tempArr[i] > max)
    {
      max = tempArr[i];
      maxDay = i;
    }
  }

  return maxDay + 1;
}