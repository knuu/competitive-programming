//
//  AOJ0583.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int n,a[3],i,j,k,temp;
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n-1; i++) {
        if (a[i]<a[i+1]) {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    for (i=1; i<=a[n-1]; i++) {
        for (j=0; j<n; j++) {
            if (a[j]%i!=0) break;
        }
        if (j==n) printf("%d\n",i);
    }
    return 0;
}