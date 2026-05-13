#include <stdio.h>

int main() {
    int i,j, arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("enter element [%d,%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("\nThe elements entered are:\n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
    
    return 0;
}