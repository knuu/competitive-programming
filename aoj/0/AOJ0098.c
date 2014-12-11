//
//  AOJ0098.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
int sumsm(int matrix[][100],int sc,int sr,int lc,int lr);
int main(void) {
    int num,i,j,k,l,max=-10000,matrix[100][100];
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        for (j=0;j<num;j++) scanf("%d",&matrix[i][j]);
    }
    
    for (i=0; i<num; i++) {
        for (j=0; j<num; j++) {
            for (k=i; k<num; k++) {
                for (l=j; l<num; l++) {
                    if (sumsm(matrix,i,j,k,l)>max) max=sumsm(matrix,i,j,k,l);
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}

int sumsm(int matrix[][100],int sc,int sr,int lc,int lr) {
    int i,j,sum=0;
    for (i=sc; i<=lc; i++) {
        for (j=sr; j<=lr; j++) sum+=matrix[i][j];
    }
    return sum;
}