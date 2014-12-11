//
//  AOJ0500.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
int main(void) {
    int num,ta,tb,sca,scb,i;
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        sca=0,scb=0;
        for (i=0; i<num; i++) {
            scanf("%d %d\n",&ta,&tb);
            if (ta>tb) {
                sca+=ta+tb;
            } else if (ta<tb) {
                scb+=ta+tb;
            } else {
                sca+=ta;
                scb+=tb;
            }
        }
        printf("%d %d\n",sca,scb);
    }
    return 0;
}