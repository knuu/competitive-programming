//
//  ALDS3-1-A.c
//  
//
//  Created by knuu on 2014/05/01.
//
//

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int sp=0,stack[101];
    char temp[8];
    while (scanf(" %s",temp)!=EOF) {
        if (temp[0]=='+') {
            sp--;
            stack[sp-1]+=stack[sp];
        } else if (temp[0]=='-') {
            sp--;
            stack[sp-1]-=stack[sp];
        } else if (temp[0]=='*') {
            sp--;
            stack[sp-1]*=stack[sp];
        } else {
            stack[sp]=atoi(temp);
            sp++;
        }
    }
    printf("%d\n",stack[0]);
    return 0;
}