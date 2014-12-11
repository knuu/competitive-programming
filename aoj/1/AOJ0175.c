//
//  AOJ0175.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
#define FOUR 4
long long n_base(long long n,long long num);
int main(void) {
    long long num;
    while (1) {
        scanf("%lld",&num);
        if (num==-1) break;
        printf("%lld\n",n_base(FOUR,num));
    }
    return 0;
}

long long n_base(long long n,long long num) {
    long long i=1,ans=0;
    while (num/n!=0||num%n!=0) {
        ans+=(num%n)*i;
        i*=10;
        num/=n;
    }
    return ans;
}