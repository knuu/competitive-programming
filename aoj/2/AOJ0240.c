//
//  AOJ0240.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
int main(void) {
    int n,y,b,r,t,num,i,j;
    double max,temp;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        max=0.0;
        scanf("%d",&y);
        for (i=0; i<n; i++) {
            scanf("%d %d %d",&b,&r,&t);
            if (t==1) {
                temp=1.0+y*r/100.0;
            } else {
                temp=1.0;
                for (j=0; j<y; j++) {
                    temp*=(1.0+y/100.0);
                }
            }
            if (max>temp) {
                max=temp;
                num=b;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}