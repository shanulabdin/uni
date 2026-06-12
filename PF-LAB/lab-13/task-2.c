#include <stdio.h>

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("employee_details.txt", "r");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}