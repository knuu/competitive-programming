//
//  AOJ0587.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
int main(void) {
    int n,car,in,out,i,max;
    scanf("%d %d",&n,&car);
    max=car;
    for (i=0; i<n; i++) {
        scanf("%d %d",&in,&out);
        car=car+in-out;
        if (car<0) break;
        if (car>max) max=car;
    }
    if (car<0) {
        printf("0\n");
    } else {
        printf("%d\n",max);
    }
    return 0;
}