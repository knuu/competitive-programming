//
//  AOJ0102.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
int main(void) {
    int matrix[11][11],num,i,j;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        matrix[num][num]=0;
        for (i=0; i<num; i++) {
            matrix[i][num]=0;
            for (j=0; j<num; j++) {
                if (i==0) matrix[num][j]=0;
                scanf("%d",&matrix[i][j]);
                matrix[i][num]+=matrix[i][j];
                matrix[num][j]+=matrix[i][j];
                matrix[num][num]+=matrix[i][j];
            }
        }
        for (i=0; i<=num; i++) {
            for (j=0; j<=num; j++) printf("%5d",matrix[i][j]);
            printf("\n");
        }
    }
    return 0;
}