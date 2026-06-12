#include <stdio.h>

int main() {
    FILE *fp;
    int num;

    fp = fopen("program.txt", "r");

    fscanf(fp, "%d", &num);

    printf("%d", num);

    fclose(fp);

    return 0;
}