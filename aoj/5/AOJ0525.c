//
//  AOJ0525.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int senbei[10][10000],c,r,temp;
    while (1) {
        scanf("%d %d",&c,&r);
        if (c==0&&r==0) break;
        for (i=0; i<c; i++) {
            for (j=0; j<r; j++) scanf("%d",&senbei[i][j]);
        }
        int max=0,mnum[2]={-1,-1};
        for (i=0; i<c; i++) {
            temp=0;
            for (j=0; j<r; j++) if (senbei[i][j]==0) temp++;
            if (temp>max) {
                max=temp;
                mnum[0]=0,mnum[1]=i;
            }
        }
        for (i=0; i<r; i++) {
            temp=0;
            for (j=0; j<c; j++) if (senbei[j][i]==0) temp++;
            if (temp>max) {
                max=temp;
                mnum[0]=1,mnum[1]=j;
            }
        }
        
    }
}