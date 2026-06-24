#include <stdio.h>

int main() {
    float pkr = 0.0, usd = 0.0;
    
    printf("Enter the amount in USD: ");
    scanf("%f", &usd);

    pkr = usd * 285.0;

    printf("%.2f USD is equal to %.2f PKR", usd, pkr);

    return 0;
}