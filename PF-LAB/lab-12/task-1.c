#include <stdio.h>
#include <string.h>

int main() {
    char first[50], last[50], full[100];

    printf("Enter first name: ");
    scanf("%s", first);

    printf("Enter last name: ");
    scanf("%s", last);

    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);

    printf("Full Name: %s", full);

    return 0;
}