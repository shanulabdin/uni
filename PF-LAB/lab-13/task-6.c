#include <stdio.h>

int main() {
    FILE *fp;
    int num, sum = 0;

    fp = fopen("numbers.txt", "r");

    while (fscanf(fp, "%d", &num) != EOF) {
        sum = sum + num;
    }

    printf("Sum = %d", sum);

    fclose(fp);

    return 0;
}