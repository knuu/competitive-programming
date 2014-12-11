//
//  AOJ2440.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    char t[11];
    int n,m,i,j,key=0;
    char u[256][11];
    scanf("%d\n",&n);
    for (i=0; i<n; i++) scanf(" %s",u[i]);
    scanf(" %d",&m);
    for (i=0; i<m; i++) {
        scanf(" %s",t);
        for (j=0; j<n; j++) {
            if (strcmp(t,u[j])==0) break;
        }
        if (j==n) {
            printf("Unknown %s\n",t);
        } else if (key==0) {
            key=1;
            printf("Opened by %s\n",t);
        } else {
            key=0;
            printf("Closed by %s\n",t);
        }
    }
    return 0;
}