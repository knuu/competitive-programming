//
//  AOJ0078.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
int main(void) {
    int n,i,j,row,column;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        int square[n][n];
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) square[i][j]=0;
        }
        for (i=1;i<=n*n;i++) {
            if (i==1) {
                row = n/2+1;
                column = n/2;
                square[row][column]=i;
                row++;
                column++;
            } else {
                if (column>=n&&row>=n) {
                	row = 1;
                	column = n-1;
                }
                if (column>=n) {
                    column = 0;
                    i--;
                    continue;
                }
                if (row>=n) {
                    row = 0;
                    i--;
                    continue;
                }
                if (square[row][column]!=0) {
                    row++;
                    column--;
                    i--;
                    continue;
                }
                square[row][column]=i;
                row++;
                column++;
            }
            
        }
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) printf("%4d",square[i][j]);
            printf("\n");
        }
    }
    return 0;
}