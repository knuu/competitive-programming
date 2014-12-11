//
//  AOJ10019.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    int x,sum,i;
    char string[1001];
    while (1) {
        scanf("%s",string);
        if (string[0]=='0'&&string[1]=='\0') break;
        sum=0,i=0;
        while (string[i]!='\0') {
            sum+=string[i]-'0';
            i++;
        }
        printf("%d\n",sum);
    }
    return 0;
}