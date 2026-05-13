#include <stdio.h>
void addFun();
void subFun();
void prodFun();
float div();

int main() {
    float var = 0;
    var = div();
    
    printf("\nOut put from MAIN func b/a = %.2f", var);
    
    return 0;
}

float div()
{
    float a, b, c=0;
    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);
    
    c = a/b;
    
    return c;
}