//
//  AOJ0107.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int l1,l2,l3,num,fr,temp,i;
    double rad;
    while (1) {
        scanf("%d %d %d",&l1,&l2,&l3);
        if (l1==0&&l2==0&&l3==0) break;
        if (l1>l2) {
            temp=l1;
            l1=l2;
            l2=temp;
        }
        if (l2>l3) {
            temp=l2;
            l2=l3;
            l3=temp;
        }
        rad=(l1*l1+l2*l2)/4.0;
        scanf("%d",&num);
        for (i=0; i<num; i++) {
            scanf("%d",&fr);
            if (rad<1.0*fr*fr) {
                printf("OK\n");
            } else {
                printf("NA\n");
            }
        }
    }
    return 0;
}