//
//  AOJ0085.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    int m,n,player[1000],count,out,potato,i;
    while (1) {
        scanf("%d %d",&n,&m);
        if (m==0&&n==0) break;
        for (i=0; i<n; i++) player[i]=0;
        count=0,potato=0,out=0;
        while (out<n-1) {
            while (count<m) {
                while (player[potato]!=0) {
                    potato++;
                    if (potato==n) potato=0;
                }
                potato++;
                if (potato==n) potato=0;
                count++;
            }
            if (potato==0) {
                player[n-1]=1;
            } else {
                player[potato-1]=1;
            }
            out++;
            count=0;
        }
        while (player[potato]!=0) {
            potato++;
            if (potato==n) potato=0;
        }
        printf("%d\n",potato+1);
    }
    return 0;
}