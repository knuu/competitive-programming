//
//  AOJ0100.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    long long num,data[4001],i,j,employee[4001],price,amount,flag,sp;
    while (1) {
        scanf("%lld\n",&num);
        if (num==0) break;
        for (i=1;i<=4000;i++) data[i]=0;
        flag=0;
        sp=0;
        for (i=0;i<num;i++) {
            scanf("%lld %lld %lld\n",&employee[sp],&price,&amount);
            data[employee[sp]]+=price*amount;
            if (data[employee[sp]]>=1000000) flag=1;
            for (j=0; j<sp; j++) {
                if (employee[sp]==employee[j]) {
                	sp--;
                	break;
                }
            }
            sp++;
        }
        if (flag==0) {
            printf("NA\n");
        } else {
            for (i=0; i<sp; i++) {
                if (data[employee[i]]>=1000000) printf("%lld\n",employee[i]);
            }
        }
    }
    return 0;
}