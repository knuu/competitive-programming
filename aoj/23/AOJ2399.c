//
//  AOJ2399.c
//  
//
//  Created by n_knuu on 2014/03/22.
//
//

#include <stdio.h>
int main(void) {
    int n,info[101][101],i,j,m,k,temp,list[100],flag,count;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++) info[i][j]=0;
        }
        for (i=1; i<=n; i++) {
            scanf("%d",&m);
            for (j=0; j<m; j++) {
                scanf("%d",&temp);
                info[i][temp]=1;
            }
        }
        scanf("%d",&k);
        for (i=0; i<k; i++) scanf("%d",&list[i]);
        flag=0,count=0;
        for (i=1; i<=n; i++) {
            for (j=0; j<k; j++) {
                if (info[i][list[j]]!=1) break;
            }
            if (j==k) {
                flag=i;
                count++;
            }
            if (count>1) break;
        }
        if (count==1) {
            printf("%d\n",flag);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}