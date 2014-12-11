//
//  AOJ0554.c
//  
//
//  Created by n_knuu on 2014/04/05.
//
//

#include <stdio.h>
int main(void) {
    int sec=0,temp,i;
    for (i=0; i<4; i++) {
        scanf("%d",&temp);
        sec+=temp;
    }
    printf("%d\n%d\n",sec/60,sec%60);
    return 0;
}