//
//  AOJ2418.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int num,ten,hundred,limit,coin[100][2],i,left=0;
    scanf("%d %d %d %d",&num,&ten,&hundred,&limit);
    for (i=0; i<num; i++) scanf("%d %d",&coin[i][0],&coin[i][1]);
    i=0;
    while (coin[i][0]!=0||coin[i][1]!=0) {
        if (coin[i][0]!=0) {
            coin[i][0]--;
            ten++;
            if (ten>limit) break;
            if (++left==9) left=0;
        } else {
            coin[i][1]--;
            ten-=left+1;
            if (ten<0) break;
            coin[i][0]=left+1;
            left=0;
        }
        if (++i==num) i=0;
    }
    printf("%d\n",i+1);
    return 0;
}