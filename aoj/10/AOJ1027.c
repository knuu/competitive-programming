//
//  AOJ1027.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
int main(void) {
    int kind,i,sum,temp;
    while (1) {
        scanf("%d",&kind);
        if (kind==0) break;
        sum=0;
        for (i=0; i<kind*(kind-1)/2; i++) {
            scanf("%d",&temp);
            sum+=temp;
        }
        printf("%d\n",sum/(kind-1));
    }
    return 0;
}