#include <stdio.h>

int main()
{
  char name[20];
  int age;

  FILE *fp;
  fp = fopen("student.txt", "r");


  fscanf(fp, "%s %d", name, &age);

  printf("%s %d", name, age);

  fclose(fp);

  return 0;
}