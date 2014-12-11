//
//  AOJ0206.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>
#define MONTH 12
int main(void) {
    int cost,income[MONTH],expense[MONTH],savings,i,flag;
    while (1) {
        scanf("%d",&cost);
        if (cost==0) break;
        savings=0,flag=0;
        for (i=0;i<MONTH;i++) {
            scanf("%d %d",&income[i],&expense[i]);
            savings+=income[i]-expense[i];
            if (flag==0&&savings>=cost) flag=i+1;
        }
        if (flag==0) {
            printf("NA\n");
        } else {
            printf("%d\n",flag);
        }
    }
    return 0;
}