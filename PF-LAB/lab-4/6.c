#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("1. Kilometers to Miles\n");
    printf("2. Meters to Feet\n");
    printf("3. Centimeters to Inches\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("Miles = %.2f", value * 0.621);
            break;

        case 2:
            printf("Feet = %.2f", value * 3.281);
            break;

        case 3:
            printf("Inches = %.2f", value * 0.394);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}