//
//  AOJ0047.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    char t1,t2,ball='A';
    while (scanf("%c,%c\n",&t1,&t2)!=EOF) {
        if (ball==t1) {
            ball = t2;
        } else if (ball==t2) {
            ball = t1;
        }
    }
    printf("%c\n",ball);
    return 0;
}