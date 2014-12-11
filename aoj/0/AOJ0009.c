//
//  AOJ0009.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
#include <math.h>

#define MAX 999999

int main(void) {
    int sieve[MAX+1]={0},count,i,j,num;
    sieve[1]=1;
    for (i=2; i<=sqrt(MAX); i++) {
        if (sieve[i]==0) {
            for (j=2*i; j<=MAX; j+=i) sieve[j]=1;
        }
    }
    while (scanf("%d",&num)!=EOF) {
        count=0;
        for (i=2; i<=num; i++) {
            if (sieve[i]==0) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}