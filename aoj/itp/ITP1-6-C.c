//
//  ITP1-6-C.c
//  
//
//  Created by n_knuu on 2014/03/13.
//
//

#include <stdio.h>
int main(void) {
    int house[4][3][10]={{{0}}},num,i,j,k,b,f,r,v;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%d %d %d %d",&b,&f,&r,&v);
        house[b-1][f-1][r-1]+=v;
    }
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<10; k++) printf(" %d",house[i][j][k]);
            printf("\n");
        }
        if (i!=3) {
            for (j=0; j<20; j++) printf("#");
            printf("\n");
        }
    }
    return 0;
}