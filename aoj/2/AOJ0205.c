//
//  AOJ0205.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    int hand[5],kind[3][2],i,num;
    while (1) {
        scanf("%d",&hand[0]);
        if (hand[0]==0) break;
        for (i=0; i<3; i++) kind[i][0]=0,kind[i][1]=0;
        scanf("%d %d %d %d",&hand[1],&hand[2],&hand[3],&hand[4]);
        for (i=0; i<5; i++) kind[hand[i]-1][0]++;
        if ((kind[0][0]>0&&kind[1][0]>0&&kind[2][0]>0)||kind[0][0]==5||kind[1][0]==5||kind[2][0]==5) {
            kind[0][1]=3,kind[1][1]=3,kind[2][1]=3;
        } else if (kind[0][0]>0&&kind[1][0]>0) {
            kind[0][1]=1,kind[1][1]=2;
        } else if (kind[1][0]>0&&kind[2][0]>0) {
            kind[1][1]=1,kind[2][1]=2;
        } else if (kind[2][0]>0&&kind[0][0]>0) {
            kind[2][1]=1,kind[0][1]=2;
        }
        for (i=0; i<5; i++) {
            printf("%d\n",kind[hand[i]-1][1]);
        }
    }
    return 0;
}