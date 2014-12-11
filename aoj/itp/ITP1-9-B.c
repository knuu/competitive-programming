//
//  ITP1-9-B.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int m,h,i,j;
    char string[202],temp[202];
    while (1) {
        scanf("%s\n",string);
        if (strcmp(string,"-")==0) break;
        scanf("%d\n",&m);
        for (i=0; i<m; i++) {
            scanf("%d\n",&h);
            for (j=0; j<h; j++) temp[j]=string[j];
            for (j=0; j<strlen(string)-h; j++) string[j]=string[j+h];
            for (j=0; j<h; j++) string[strlen(string)-h+j]=temp[j];
        }
        printf("%s\n",string);
    }
    return 0;
}