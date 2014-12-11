//
//  AOJ10032.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int sp=0;
    char block[1000],inst[4];
    while (1) {
        scanf(" %s",inst);
        if (strcmp(inst,"quit")==0) break;
        if (strcmp(inst,"pop")==0) {
            printf("%c\n",block[sp-1]);
            sp--;
        } else {
            scanf(" %c\n",&block[sp]);
            sp++;
        }
    }
    return 0;
}