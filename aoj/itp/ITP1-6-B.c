//
//  ITP1-6-B.c
//  
//
//  Created by n_knuu on 2014/03/13.
//
//

#include <stdio.h>
int main(void) {
    int num,card[4][13]={{0}},i,temp;
    char face;
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        scanf("%c %d\n",&face,&temp);
        if (face=='S') {
            card[0][temp-1]=1;
        } else if (face=='H') {
            card[1][temp-1]=1;
        } else if (face=='C') {
            card[2][temp-1]=1;
        } else if (face=='D') {
            card[3][temp-1]=1;
        }
    }
    for (i=0; i<13; i++) if (card[0][i]==0) printf("S %d\n",i+1);
    for (i=0; i<13; i++) if (card[1][i]==0) printf("H %d\n",i+1);
    for (i=0; i<13; i++) if (card[2][i]==0) printf("C %d\n",i+1);
    for (i=0; i<13; i++) if (card[3][i]==0) printf("D %d\n",i+1);
    return 0;
}