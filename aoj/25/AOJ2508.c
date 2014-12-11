//
//  AOJ2508.c
//  
//
//  Created by n_knuu on 2014/04/05.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    char station[53]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int num,i,place,a[101];
    char string[101];
    while (scanf("%d",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) scanf("%d",&a[i]);
        scanf(" %s",string);
        for (i=0; i<strlen(string); i++) {
            if (islower(string[i])) {
                place=string[i]-'a'-a[i%num];
            } else {
                place=string[i]-'A'+26-a[i%num];
            }
            if (place<0) place+=52;
            printf("%c",station[place]);
        }
        printf("\n");
    }
    return 0;
}