//
//  AOJ0112.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    long long num,i,j,sum,a[10002],temp,key;
    while (scanf("%lld",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) {
            scanf("%lld",&key);
            if (i==0) {
                a[i]=key;
            } else {
                j=i-1;
                while (key<a[j]&&j>=0) {
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=key;
            }
        }
        sum=0;
        for (i=0; i<num-1; i++) {
            sum+=a[i]*(num-1-i);
        }
        printf("%lld\n",sum);
    }
    return 0;
}