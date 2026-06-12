#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("student_data.txt", "w");

    fclose(fp);

    return 0;
}