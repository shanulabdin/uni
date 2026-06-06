#include <stdio.h>

int topper(int marks[][6], int students, int subjects);

int main(){
  int students = 5, subjects = 6, topStudent = 0;
  int marks[5][6] = {
    {50, 60, 70, 65, 80, 75},
    {80, 75, 90, 85, 70, 60},
    {40, 85, 60, 55, 65, 70},
    {90, 88, 92, 85, 80, 95},
    {60, 55, 65, 70, 75, 80}
  };
  
  topStudent = topper(marks, students, subjects);

  printf("First position goes to student number: %d", topStudent);

  return 0;
}

int topper(int marks[][6], int students, int subjects){
  int total, maxTotal = 0, topStudent = 0;

  for(int i = 0; i < students; i++){
    total = 0;
    for(int j = 0; j < subjects; j++){
      total = total + marks[i][j];
    }

    if(total > maxTotal){
      maxTotal = total;
      topStudent = i;
    }
  }

  return topStudent + 1;
}