//
//  AOJ0222.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
#include <math.h>
int prime(int num);
int main(void) {
    int i,j,num,flag;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        if (num%2==0) num--;
        for (i=num; ; i-=2) {
            if (prime(i-8)==1&&prime(i-6)==1&&prime(i-2)==1&&prime(i)==1) break;
        }
        printf("%d\n",i);
    }
    return 0;
}

int prime(int num) {
    int i,j;
    if (num%2==0&&num!=2) return 0;
    for (i=3; i<=sqrt(num); i+=2) {
        if (num%i==0) return 0;
    }
    return 1;
}