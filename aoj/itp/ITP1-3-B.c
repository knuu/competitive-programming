//
//  ITP1-3-B.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int i,n;
    for (i=1; ; i++) {
        scanf("%d",&n);
        if (n==0) break;
        printf("Case %d: %d\n",i,n);
    }
    return 0;
}