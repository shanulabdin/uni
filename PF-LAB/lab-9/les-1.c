#include <stdio.h>
void addFun();
void subFun();
void prodFun();

int main() {
    prodFun();
    return 0;
}

void prodFun()
{
    int a, b, c=0;
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    
    c = a*b;
    printf("\n%d * %d = %d", a, b, c);
}

void subFun()
{
    int a, b, c=0;
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    
    c = a-b;
    printf("\n%d - %d = %d", a, b, c);
}

void addFun()
{
    int a, b, c=0;
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    
    c = a+b;
    printf("\n%d + %d = %d", a, b, c);
}