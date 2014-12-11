//
//  AOJ2522.c
//  
//
//  Created by n_knuu on 2014/04/10.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int num=0,upper=0,lower=0,i;
    char pass[21];
    scanf("%s\n",pass);
    if (strlen(pass)<6) {
        printf("INVALID\n");
        return 0;
    }
    for (i=0; i<strlen(pass); i++) {
        if (isdigit(pass[i])) {
            num=1;
        } else if (islower(pass[i])) {
            lower=1;
        } else if (isupper(pass[i])) {
            upper=1;
        }
    }
    if (num==1&&lower==1&&upper==1) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
    return 0;
}