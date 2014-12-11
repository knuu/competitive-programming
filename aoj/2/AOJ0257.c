//
//  AOJ0257.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
int main(void) {
    int b1,b2,b3;
    scanf("%d %d %d",&b1,&b2,&b3);
    if (b3==1||(b1==1&&b2==1)) {
        printf("Open\n");
    } else {
        printf("Close\n");
    }
    return 0;
}