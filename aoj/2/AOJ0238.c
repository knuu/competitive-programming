//
//  AOJ0238.c
//  
//
//  Created by n_knuu on 2014/03/20.
//
//

#include <stdio.h>
int main(void) {
    int t,n,s,f,i;
    while (1) {
        scanf("%d",&t);
        if (t==0) break;
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            scanf("%d %d",&s,&f);
            t-=(f-s);
        }
        if (t<=0) {
            printf("OK\n");
        } else {
            printf("%d\n",t);
        }
    }
    return 0;
}