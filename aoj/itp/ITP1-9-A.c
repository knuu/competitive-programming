//
//  ITP1-9-A.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    int i,count=0;
    char word[12],text[1001];
    scanf(" %s",word);
    while (1) {
        scanf(" %s",text);
        if (strcmp(text,"END_OF_TEXT")==0) break;
        for (i=0; i<strlen(text); i++) text[i]=tolower(text[i]);
        if (strcmp(text,word)==0) count++;
    }
    printf("%d\n",count);
    return 0;
}