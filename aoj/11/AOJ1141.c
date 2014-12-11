//
//  AOJ1141.c
//  
//
//  Created by knuu on 2014/05/18.
//
//

#include <stdio.h>
#include <math.h>
#define MAX 1000000
int main(void) {
    int a,d,n,i,j,sieve[MAX+1]={0};
    sieve[1]=1;
    for (i=2; i<=sqrt(MAX); i++) {
        if (sieve[i]==0) {
            for (j=2*i; j<=MAX; j+=i) sieve[j]=1;
        }
    }
    while (scanf("%d %d %d",&a,&d,&n)!=EOF&&(a!=0||d!=0||n!=0)) {
        i=0;
        while (n!=0) {
            if (sieve[a+i*d]==0) {
                n--;
            }
            i++;
        }
        printf("%d\n",a+(i-1)*d);
    }
    return 0;
}