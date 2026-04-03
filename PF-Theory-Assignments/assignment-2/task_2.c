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

  printf("%s", 
    (average >= 85) ? "Grade A." :
    (average >= 70 && average < 84) ? "Grade B." :
    (average >= 50 && average < 69) ? "Grade C." :
    (average >= 40 && average < 54) ? "Grade D." : "Grade F."
  );

  printf("%s", (average >= 80) ? "\nScholarship Eligible." : "");

  return 0;
}