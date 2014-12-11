//
//  AOJ1172.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <math.h>
#define MAX 123456
int main(void) {
    int num,sieve[MAX*2+1]={0},i,j,count;
    for (i=4; i<=2*MAX; i+=2) sieve[i]=1;
    for (i=3; i<=sqrt(MAX*2); i+=2) {
        if (sieve[i]==0) for (j=2*i; j<=2*MAX; j+=i) sieve[j]=1;
    }
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        count=0;
        for (i=num+1; i<=num*2; i++) {
            if (sieve[i]==0) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}