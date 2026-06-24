#include <stdio.h>

int main() {
    float c, f = 0.0;
    
    printf("Enter temperature in celcius: ");
    scanf("%f", &c);

    f = (9.0/5.0) * c + 32;
    
    printf("%0.2f Celcius is equal to %0.2f Fahrenheit.", c, f);
    
    return 0;
}