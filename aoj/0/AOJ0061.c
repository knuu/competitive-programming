//
//  AOJ0061.c
//  
//
//  Created by n_knuu on 2014/02/26.
//
//

#include <stdio.h>
int main(void) {
    int rank[100][3]={0},num,point,i,j,temp,n=0;
    while (1) {
        scanf("%d,%d",&num,&point);
        if(num==0&&point==0) break;
        rank[n][0]=num;
        rank[n][1]=point;
        n++;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n-i-1; j++) {
            if (rank[j][1]<rank[j+1][1]) {
                temp=rank[j][1];
                rank[j][1]=rank[j+1][1];
                rank[j+1][1]=temp;
                temp=rank[j][0];
                rank[j][0]=rank[j+1][0];
                rank[j+1][0]=temp;
            }
        }
    }
    for (i=0; i<n; i++) {
        if (i==0) {
            rank[i][2]=1;
        } else if (rank[i][1]==rank[i-1][1]) {
            rank[i][2]=rank[i-1][2];
        } else {
            rank[i][2]=rank[i-1][2]+1;
        }
    }
    while (scanf("%d",&num)!=EOF) {
        for (i=0; ; i++) {
            if (rank[i][0]==num) {
                printf("%d\n",rank[i][2]);
                break;
            }
        }
    }
    return 0;
}