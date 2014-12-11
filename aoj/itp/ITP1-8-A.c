//
//  ITP1-8-A.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int i;
    char string[1200];
    fgets(string,sizeof(string),stdin);
    for (i=0; i<strlen(string); i++) {
        if (isalpha(string[i])) {
            if (islower(string[i])) {
                printf("%c",toupper(string[i]));
            } else {
                printf("%c",tolower(string[i]));
            }
        } else {
            printf("%c",string[i]);
        }
    }
    return 0;
}