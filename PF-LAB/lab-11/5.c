#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("Address of a = %p\n", &a);
    printf("Pointer value = %p\n", p);

    *p = 50;

    printf("Updated value = %d", a);

    return 0;
}