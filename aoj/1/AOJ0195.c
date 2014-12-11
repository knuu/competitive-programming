//
//  AOJ0195.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int mo,af,i,max,shop;
    while (scanf("%d %d",&mo,&af)!=EOF&&(mo!=0||af!=0)) {
        shop=0,max=mo+af;
        for (i=0; i<4; i++) {
            scanf("%d %d",&mo,&af);
            if (mo+af>max) {
                max=mo+af;
                shop=i+1;
            }
        }
        printf("%c %d\n",shop+'A',max);
    }
    return 0;
}