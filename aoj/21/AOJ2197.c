//
//  AOJ2197.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int num,i,count,temp1;
    double limit,temp2;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        count=0;
        limit=(sqrt(1+8*num)+1)/2;
        for (i=2; i<limit; i++) {
            temp2=1.0*num/i-(i-1)/2.0;
            temp1=temp2;
            if (temp1*1.0==temp2) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}