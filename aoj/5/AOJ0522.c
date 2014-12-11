//
//  AOJ0522.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int ioi,joi,i,j;
    char str[10001];
    while (scanf("%s\n",str)!=EOF) {
        ioi=0,joi=0;
        for (i=0; i<strlen(str)-2; i++) {
            if (str[i]=='J'&&str[i+1]=='O'&&str[i+2]=='I') joi++;
            if (str[i]=='I'&&str[i+1]=='O'&&str[i+2]=='I') ioi++;
        }
        printf("%d\n%d\n",joi,ioi);
    }
    return 0;
}