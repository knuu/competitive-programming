//
//  AOJ0174.c
//  
//
//  Created by n_knuu on 2014/04/05.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int a,b,i;
    char serve[101];
    while (scanf(" %s",serve)!=EOF&&(serve[0]-'0')!=0) {
        a=0,b=0;
        for (i=0; i<strlen(serve); i++) {
            if (i==0) {
                continue;
            } else {
                if (serve[i]=='A') {
                    a++;
                } else {
                    b++;
                }
            }
        }
        if (a>b) {
            a++;
        } else {
            b++;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}