//
//  AOJ0114.c
//  
//
//  Created by knuu on 2014/05/14.
//
//

#include <stdio.h>
long long gcd(long long a, long long b);
int main(void) {
    long long a1,m1,a2,m2,a3,m3,count[2],x,y,z,two,three;
    while (scanf("%lld%lld%lld%lld%lld%lld",&a1,&m1,&a2,&m2,&a3,&m3)!=EOF&&a1!=0) {
        count[0]=0,count[1]=0,count[2]=0,x=1,y=1,z=1;
        do {
            x=(a1*x)%m1;
            count[0]++;
        } while (x!=1);
        do {
            y=(a2*y)%m2;
            count[1]++;
        } while (y!=1);
        do {
            z=(a3*z)%m3;
            count[2]++;
        } while (z!=1);
        two=gcd(count[0],count[1]);
        two=count[0]*count[1]/two;
        three=gcd(two,count[2]);
        printf("%lld\n",two*count[2]/three);
    }
    return 0;
}

long long gcd(long long a, long long b) {
    long long temp;
    if (a<b) {
        temp=a;
        a=b;
        b=temp;
    }
    while (a%b!=0) {
        a%=b;
        temp=a;
        a=b;
        b=temp;
    }
    return b;
}