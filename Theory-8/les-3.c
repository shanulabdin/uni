#include <stdio.h>

int main() {
    int i,j, sum=0, colSum=0, arr[2][3];
    float average, percentage;
    
    for(i=0; i<2; i++){
        printf("\nenter marks for student %d: \n", i+1);
        for(j=0; j<3; j++){
            printf("marks for subject %d: ", j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("\n\t\tMarksheet:\n");
    for(i=0; i<2; i++){
        sum = 0;
        printf("Student %d: ", i+1);
        for(j=0; j<3; j++){
            printf("%d, ", arr[i][j]);
            sum = sum + arr[i][j];
        }
        printf(" Total: %d|", sum);
        
        average = (float)sum/j;
        printf(" Average: %.2f|", average);
        
        percentage = ((float)sum/(j*100))*100;
        printf(" Percentage: %.2f%%|", percentage);
        
        char grade;
        
        grade = (percentage < 50) ? 'F' :
                (percentage < 65) ? 'C' :
                (percentage < 90) ? 'B' : 'A';
        
        printf(" Grade: %c |", grade);
        
        printf("\n");
    }
    
    return 0;
}