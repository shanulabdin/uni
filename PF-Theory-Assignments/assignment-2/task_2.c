#include <stdio.h>

int main()
{
  float sub_1, sub_2, sub_3, sub_4, sub_5;

  printf("Enter marks of Subject 1: ");
  scanf("%f", &sub_1);
  printf("Enter marks of Subject 2: ");
  scanf("%f", &sub_2);
  printf("Enter marks of Subject 3: ");
  scanf("%f", &sub_3);
  printf("Enter marks of Subject 4: ");
  scanf("%f", &sub_4);
  printf("Enter marks of Subject 5: ");
  scanf("%f", &sub_5);

  float average = (sub_1 + sub_2 + sub_3 + sub_4 + sub_5) / 5;

  if (average >= 85)
  {
    printf("Grade A.");
    printf("Scholarship Eligible.");
  }
  else if (average >= 70 && average < 84)
  {
    printf("Grade B.");
  }
  else if (average >= 50 && average < 69)
  {
    printf("Grade C.");
  }
  else if (average >= 40 && average < 54)
  {
    printf("Grade D.");
  }
  else
  {
    printf("Grade F.");
  }

  if (average >= 80)
  {
    printf("\nScholarship Eligible.");
  }

  return 0;
}