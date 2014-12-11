//
//  AOJ2217.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>
int main(void) {
    int num,floor[100][100][3],i,j,k,jump[2],count;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        for (i=0; i<num; i++) {
            for (j=0; j<num; j++) {
                scanf("%d %d",&floor[j][i][0],&floor[j][i][1]);
                floor[j][i][2]=0;
            }
        }
        int check[num*num][2],sp;
        count=0;
        for (i=0; i<num; i++) {
            for (j=0; j<num; j++) {
                jump[0]=j,jump[1]=i,sp=0;
                if (floor[jump[0]][jump[1]][2]==0) {
                    while (floor[jump[0]][jump[1]][2]==0) {
                        floor[jump[0]][jump[1]][2]=1;
                        check[sp][0]=jump[0];
                        check[sp][1]=jump[1];
                        sp++;
                        jump[0] = floor[check[sp-1][0]][check[sp-1][1]][0];
                        jump[1] = floor[check[sp-1][0]][check[sp-1][1]][1];
                    }
                    for (k=0; k<sp; k++) {
                        if (check[k][0]==jump[0]&&check[k][1]==jump[1]) {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}