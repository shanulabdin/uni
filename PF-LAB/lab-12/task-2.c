#include <stdio.h>

int main() {
    char name[100];

    printf("Enter your full name: ");
    scanf(" %[^\n]", name);

    printf("Welcome, %s!", name);

    return 0;
}