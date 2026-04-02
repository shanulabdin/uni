#include <stdio.h>
int main()
{
  int choice;
  float input, converted;

  printf("1. For Kilometers to Miles, press 1.\n");
  printf("2. Meters to Feet, Press 2.\n");
  printf("3. Centimeters to Inches, Press 3.\n");
  printf("Choose conversion type: ");

  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\nUser chose Kilometers to Miles. \n");
    printf("enter your value in Kilometers: ");
    scanf("%f", &input);

    converted = input * 0.621371;

    printf("%0.2f Kilometers is equal to %0.2f Miles.\n", input, converted);
    break;
  case 2:
    printf("\nUser chose Meters to Feet. \n");
    printf("enter your value in Meters: ");
    scanf("%f", &input);

    converted = input * 3.28084;
    printf("%0.2f Meters is equal to %0.2f Feet.\n", input, converted);
    break;
  case 3:
    printf("\nUser chose Centimeters to Inches. \n");
    printf("enter your value in Centimeters: ");
    scanf("%f", &input);

    converted = input * 0.393701;
    printf("%0.2f Centimeters is equal to %0.2f Inches.\n", input, converted);
    break;
  default:
    printf("invalid input \n");
  }
  return 0;
}