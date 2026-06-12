#include <stdio.h>

int main() {
    FILE *fp;
    char name[50], grade;
    int age;

    fp = fopen("student_info.txt", "w");

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter grade: ");
    scanf(" %c", &grade);

    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Grade: %c\n", grade);

    fclose(fp);

    return 0;
}