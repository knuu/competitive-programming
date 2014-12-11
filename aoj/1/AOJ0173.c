//
//  AOJ0173.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int mo,af,i;
    char class[16];
    for (i=0; i<9; i++) {
        scanf("%s %d %d\n",class,&mo,&af);
        printf("%s %d %d\n",class,mo+af,mo*200+af*300);
    }
    return 0;
}