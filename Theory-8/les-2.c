#include <stdio.h>

int main() {
    int i,j, sum=0, colSum=0, arr[2][3];
    
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("enter element [%d,%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("\nThe elements entered are:\n");
    for(i=0; i<2; i++){
        sum = 0;
        for(j=0; j<3; j++){
            printf("%d ", arr[i][j]);
            sum = sum + arr[i][j];
        }
        printf(" Row Sum: %d", sum);
        printf("\n");
    }
    
    printf("\nThe sum of columns:\n");
    for(int i = 0; i < 2; i++) {
        colsum = 0;
        for(int j = 0; j < 3; j++) {
            colsum += arr[j][i];
        }
        printf("Column %d sum = %d\n", i, colsum);
    }
    
    return 0;
}