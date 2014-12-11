//
//  AOJ0158.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
int main(void) {
    int num,count;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        count=0;
        while (num!=1) {
            if (num%2==0) {
                num/=2;
            } else {
                num=num*3+1;
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}