//
//  AOJ0543.c
//  
//
//  Created by n_knuu on 2014/05/01.
//
//

#include <stdio.h>
int main (void) {
    int sum,temp,i;
    while (scanf("%d",&sum)!=EOF&&sum!=0) {
        for (i=0; i<9; i++) {
            scanf("%d",&temp);
            sum-=temp;
        }
        printf("%d\n",sum);
    }
    return 0;
}