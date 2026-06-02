#include <stdio.h>

int isEven(int n) {
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}
int main() {
    printf("%d\n", isEven(4));
    printf("%d\n", isEven(7));
    return 0;
}