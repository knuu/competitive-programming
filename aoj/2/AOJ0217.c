//
//  AOJ0217.c
//  
//
//  Created by n_knuu on 2014/03/20.
//
//

#include <stdio.h>
int main(void) {
    int num,pmax,psum,temp,st1,st2,i;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        psum=0;
        for (i=0; i<num; i++) {
            scanf("%d %d %d",&temp,&st1,&st2);
            st1+=st2;
            if (st1>psum) {
                pmax=temp;
                psum=st1;
            }
        }
        printf("%d %d\n",pmax,psum);
    }
    return 0;
}