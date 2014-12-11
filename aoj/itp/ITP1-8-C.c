//
//  ITP1-8-C.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int i,alpha[26]={0};
    char string[1201];
    while (fgets(string,sizeof(string),stdin)!=NULL) {
        for (i=0; i<strlen(string); i++) {
            if (isalpha(string[i])) {
                if (islower(string[i])) {
                    alpha[string[i]-'a']++;
                } else {
                    alpha[string[i]-'A']++;
                }
            }
        }
    }
    for (i=0; i<26; i++) printf("%c : %d\n",i+'a',alpha[i]);
    return 0;
}