//
//  AOJ10020.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int alpha[26]={0},i;
    char c;
    while (scanf("%c",&c)!=EOF) {
        if (isalpha(c)!=0) {
            if (islower(c)!=0) {
                alpha[c-'a']++;
            } else {
                alpha[tolower(c)-'a']++;
            }
        }
    }
    for (i=0; i<26; i++) printf("%c : %d\n",'a'+i,alpha[i]);
    return 0;
}