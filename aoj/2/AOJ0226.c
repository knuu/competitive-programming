//
//  AOJ0226.c
//  
//
//  Created by n_knuu on 2014/03/20.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int hit,blow,i,j;
    char r[4],a[4];
    while (1) {
        scanf("%s %s\n",r,a);
        if (strcmp(r,"0")==0&&strcmp(a,"0")==0) break;
        hit=0;blow=0;
        for (i=0; i<4; i++) if (r[i]==a[i]) hit++;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) if (a[i]==r[j]) blow++;
        }
        printf("%d %d\n",hit,blow-hit);
    }
    return 0;
}