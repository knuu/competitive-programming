//
//  AOJ1041.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    int num,temp,sum,i;
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        sum=0;
        for (i=0; i<num/4; i++) {
            scanf("%d\n",&temp);
            sum+=temp;
        }
        printf("%d\n",sum);
    }
    return 0;
}