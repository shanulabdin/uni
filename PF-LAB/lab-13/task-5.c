#include <stdio.h>

int main() {
    FILE *fp;
    char name[50];
    float price;
    int quantity;

    fp = fopen("inventory.txt", "a");

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    fprintf(fp, "%s %.2f %d\n", name, price, quantity);

    fclose(fp);

    return 0;
}