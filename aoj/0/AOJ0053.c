//
//  AOJ0053.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
#include <math.h>

#define MAX 1000000
#define OVER 10000

int main(void) {
    int sieve[MAX+1]={0},count=0,i,j,num,sum[OVER+1]={0};
    sieve[1]=1;
    for (i=2; ; i++) {
        if (sieve[i]==0) {
            for (j=2*i; j<=MAX; j+=i) sieve[j]=1;
            sum[count+1]=i+sum[count];
            count++;
        }
        if (count==OVER) break;
    }
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        printf("%d\n",sum[num]);
    }
    return 0;
}
