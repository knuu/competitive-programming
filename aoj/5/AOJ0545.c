//
//  AOJ0545.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
int main(void) {
    int n,m,student[501][501],i,j,t1,t2,lp[501],check[501],count;
    while (1) {
        scanf("%d %d",&n,&m);
        if (n==0&&m==0) break;
        count=0;
        for (i=1; i<=n; i++) lp[i]=0,check[i]=0;
        for (i=0; i<m; i++) {
            scanf("%d %d",&t1,&t2);
            student[t1][lp[t1]]=t2;
            student[t2][lp[t2]]=t1;
            lp[t1]++;
            lp[t2]++;
        }
        check[1]=1;
        for (i=0; i<lp[1]; i++) {
            count++;
            check[student[1][i]]=1;
        }
        for (i=0; i<lp[1]; i++) {
            for (j=0; j<lp[student[1][i]]; j++) {
                if (check[student[student[1][i]][j]]==0) {
                    check[student[student[1][i]][j]]=1;
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}