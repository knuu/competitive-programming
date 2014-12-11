//
//  AOJ0516.c
//  
//
//  Created by n_knuu on 2014/05/02.
//
//

#include <stdio.h>
int main(void) {
    int i,j,n,k,a[100001],sum[100001],max;
    while (scanf("%d %d",&n,&k)!=EOF&&(n!=0||k!=0)) {
        max=-1000000000;
        for (i=0; i<n; i++) scanf("%d",&a[i]);
        if (k==1) {
            for (i=0; i<n; i++) {
                if (a[i]>max) max=a[i];
            }
            printf("%d\n",max);
            continue;
        }
        for (i=0; i<n-1; i++) {
            sum[i]=a[i]+a[i+1];
        }
        if (k==2) {
            for (i=0; i<n-1; i++) {
                if (sum[i]>max) max=sum[i];
            }
            printf("%d\n",max);
            continue;
        }
        for (i=0; i<k-2; i++) {
            for (j=0; j<n-2-i; j++) {
                sum[j]+=a[j+i+2];
            }
        }
        for (i=0; i<n-k+1; i++) {
            if (sum[i]>max) max=sum[i];
            
        }
        printf("%d\n",max);
    }
    return 0;
}