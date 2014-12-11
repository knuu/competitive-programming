//
//  AOJ0227.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
int main(void) {
    int i,j,n,m,p[1000],temp,sum;
    while (1) {
        scanf("%d %d",&n,&m);
        if (n==0&&m==0) break;
        sum=0;
        for (i=0; i<n; i++) scanf("%d",&p[i]);
        for (i=0; i<n; i++) {
            for (j=0; j<n-1-i; j++) {
                if (p[j]>p[j+1]) {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }
        temp=n-1;
        while ((temp+1)/m!=0) {
            for (i=0; i<m-1; i++) {
                sum+=p[temp-i];
            }
            temp-=m;
        }
        for (i=temp; i>=0; i--) {
            sum+=p[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}