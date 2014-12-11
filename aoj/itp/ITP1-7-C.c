//
//  ITP1-7-C.c
//  
//
//  Created by n_knuu on 2014/03/14.
//
//

#include <stdio.h>
int main(void) {
    int r,c,sheet[101][101]={{0}},i,j;
    scanf("%d %d",&r,&c);
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            scanf("%d",&sheet[i][j]);
            sheet[i][c]+=sheet[i][j];
            sheet[r][j]+=sheet[i][j];
            sheet[r][c]+=sheet[i][j];
        }
    }
    for (i=0; i<r+1; i++) {
        for (j=0; j<c+1; j++) {
            if (j) printf(" ");
            printf("%d",sheet[i][j]);
        }
        printf("\n");
    }
    return 0;
}