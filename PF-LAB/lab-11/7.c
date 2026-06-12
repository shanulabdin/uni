#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s;
    struct Student *p = &s;

    printf("Enter name: ");
    scanf("%s", p->name);

    printf("Enter roll number: ");
    scanf("%d", &p->roll);

    printf("Enter marks: ");
    scanf("%f", &p->marks);

    printf("Name: %s\n", p->name);
    printf("Roll Number: %d\n", p->roll);
    printf("Marks: %.2f", p->marks);

    return 0;
}