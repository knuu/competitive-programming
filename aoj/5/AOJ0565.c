//
//  AOJ0565.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
int main(void) {
    int p1,p2,p3,d1,d2,pmin,dmin;
    scanf("%d%d%d%d%d",&p1,&p2,&p3,&d1,&d2);
    if (p1<p2&&p1<p3) {
        pmin=p1;
    } else if (p2<p1&&p2<p3) {
        pmin=p2;
    } else {
        pmin=p3;
    }
    if (d1<d2) {
        dmin=d1;
    } else {
        dmin=d2;
    }
    printf("%d\n",pmin+dmin-50);
    return 0;
}