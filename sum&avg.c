#include <stdio.h>

int main() {
    // Write a C program to take three numbers as input and calculate their sum and average.
    
    int num1, num2, num3;
    
    printf("Enter number 1:\t");
    scanf("%d", &num1);
    printf("Enter number 2:\t");
    scanf("%d", &num2);
    printf("Enter number 3:\t");
    scanf("%d", &num3);

    int sum = num1 + num2 + num3;
    printf("Your Sum is: %d\n", sum);
    
    float average = sum / 3;
    printf("your average is: %.2f\n", average);

    return 0;
}