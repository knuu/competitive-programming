//
//  AOJ1004.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//
#include <stdio.h>
#include <math.h>
int main(void) {
    int n,i,j,sieve[10001]={0};
    sieve[1]=1;
    for (i=2; i<=sqrt(10000); i++) {
        if (sieve[i]==0) {
            for (j=i*2; j<=10000; j+=i) sieve[j]=1;
        }
    }
    while (scanf("%d",&n)!=EOF) {
        int count=0;
        if (n%2==0) {
            for (i=2; i<=n/2; i++) {
                if (sieve[i]==0&&sieve[n+1-i]==0) count++;
            }
            printf("%d\n",count*2);
        } else {
            for (i=2; i<=n/2; i++) {
                if (sieve[i]==0&&sieve[n+1-i]==0) count++;
            }
            if (sieve[n/2+1]==0) {
                printf("%d\n",count*2+1);
            } else {
                printf("%d\n",count*2);
            }
        }
    }
    return 0;
}