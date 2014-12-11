//
//  AOJ0576.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int wd,jap,arith,pj,pa,dj,da;
    scanf("%d%d%d%d%d",&wd,&jap,&arith,&pj,&pa);
    dj=ceil(1.0*jap/pj);
    da=ceil(1.0*arith/pa);
    if (dj>da) {
        printf("%d\n",wd-dj);
    } else {
        printf("%d\n",wd-da);
    }
    return 0;
}