//
//  AOJ0032.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void) {
    int l1,l2,l3,rec=0,loz=0;
    while(scanf("%d,%d,%d",&l1,&l2,&l3)!=EOF) {
        if(l1*l1+l2*l2==l3*l3) rec++;
        if(l1==l2) loz++;
    }
    printf("%d\n%d\n",rec,loz);
    return 0;
}