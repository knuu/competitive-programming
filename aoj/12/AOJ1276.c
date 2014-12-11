//
//  AOJ1276.c
//  
//
//  Created by knuu on 2014/05/13.
//
//

#define MAX 1299709
#include <stdio.h>
#include <math.h>
int main(void) {
    int sieve[MAX+2]={0},num,p,pn,i,j,temp;
    for (i=2; i<=sqrt(MAX); i++) {
        if (sieve[i]==0) {
            for (j=2*i; j<=MAX; j+=i) {
                sieve[j]=1;
            }
        }
    }
    while (scanf("%d",&num)!=EOF&&num!=0) {
        if (sieve[num]==0) {
            p=num,pn=num;
        } else {
            temp=num;
            while (sieve[temp]==1) {
                temp--;
            }
            p=temp;
            temp=num;
            while (sieve[temp]==1) {
                temp++;
            }
            pn=temp;
        }
        printf("%d\n",pn-p);
    }
    return 0;
}