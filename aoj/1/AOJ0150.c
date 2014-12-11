//
//  AOJ0150.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
#include <math.h>

#define MAX 10000
int main(void) {
    int sieve[MAX+1]={0},i,j,num;
    for (i=2; i<=sqrt(MAX); i++) {
        if (sieve[i]==0) {
            for (j=i*2; j<=MAX; j+=i) sieve[j]=1;
        }
    }
    while (scanf("%d",&num)!=EOF&&num!=0) {
        if (num%2==0) num--;
        while (sieve[num]!=0||sieve[num-2]!=0) {
            num-=2;
        }
        printf("%d %d\n",num-2,num);
    }
    return 0;
}