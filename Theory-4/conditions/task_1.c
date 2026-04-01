#include <stdio.h>

int main()
{
  int day;

  printf("Enter the day of the week from 1 to 7: ");
  scanf("%d", &day);

  switch(day)
  {
    case 1: printf("Monday");
      break;
    case 2: printf("Tueday");
      break;
    case 3: printf("Wednesday");
      break;
    case 4: printf("Thursday");
      break;
    case 5: printf("Friday");
      break;
    case 6: printf("Saturday");
      break;
    case 7: printf("Sunday");
      break;
    default: printf("Err: Invalid Input.");
  }

  return 0;
}