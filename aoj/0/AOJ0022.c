//
//  AOJ022.c
//  
//
//  Created by n_knuu on 2014/02/28.
//
//

#include <stdio.h>
int main(void) {
    int n,i,j,k,sum,max;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        int num[n];
        max=-500000000;
        for (i=0;i<n;i++) scanf("%d",&num[i]);
        for(i=0;i<n;i++) {
            sum=0;
            for(j=i;j<n;j++) {
                sum+=num[j];
                if(sum>max) max=sum;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}