//
//  AOJ0020.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
#include <ctype.h>

int main(void){
    char s;
    int ch;
    while(1){
        s = getchar();
        if (s=='\n') break;
        if (islower(s)!=0) {
            ch=toupper(s);
            printf("%c",ch);
        } else {
            printf("%c",s);
        }
    }
    printf("\n");
    return 0;
}