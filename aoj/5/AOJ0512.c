//
//  AOJ0512.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
#include <string.h>

#define THREE 3

int main(void) {
    int i;
    char str[1001];
    scanf("%s",str);
    for (i=0; i<strlen(str); i++) {
        if (str[i]-THREE%26>='A') {
            printf("%c",str[i]-THREE%26);
        } else {
            printf("%c",str[i]-THREE%26+26);
        }
    }
    printf("\n");
    return 0;
}