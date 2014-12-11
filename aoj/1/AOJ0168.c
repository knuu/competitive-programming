//
//  AOJ0168.c
//  
//
//  Created by n_knuu on 2014/03/17.
//
//

#include <stdio.h>
int main(void) {
    long long a1,a2,a3,a4,num,i;
    while (1) {
        scanf("%lld",&num);
        if (num==0) break;
        a1=1,a2=2,a3=4;
        if (num==1||num==2||num==3) {
            printf("1\n");
        } else {
            for (i=4; i<=num; i++) {
                a4=a1+a2+a3;
                a1=a2,a2=a3,a3=a4;
            }
            if (a4%3650==0) {
                printf("%lld\n",a4/3650);
            } else {
                printf("%lld\n",a4/3650+1);
            }
        }
    }
    return 0;
}