//
//  AOJ0134.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>
int main (void) {
    long long num,temp,sum=0,i;
    scanf("%lld\n",&num);
    for (i=0; i<num; i++) {
        scanf("%lld",&temp);
        sum+=temp;
    }
    printf("%lld\n",sum/num);
    return 0;
}