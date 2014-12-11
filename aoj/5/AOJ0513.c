//
//  AOJ0513.c
//  
//
//  Created by n_knuu on 2014/04/12.
//
//

#include <stdio.h>
int main(void) {
    int num,count,i,j,inst,card[202],shuffle[202];
    scanf("%d%d",&num,&count);
    for (i=1; i<=2*num; i++) card[i]=i;
    for (i=0; i<count; i++) {
        scanf("%d",&inst);
        if (inst==0) {
            for (j=1; j<=2*num; j++) shuffle[j]=card[j];
            for (j=1; j<=num; j++) {
                card[2*j-1]=shuffle[j];
                card[2*j]=shuffle[j+num];
            }
        } else {
            for (j=1; j<=inst; j++) shuffle[j]=card[j];
            for (j=1; j<=2*num-inst; j++) card[j]=card[j+inst];
            for (j=2*num-inst+1; j<=2*num; j++) card[j]=shuffle[j-2*num+inst];
        }
    }
    for (i=1; i<=2*num; i++) printf("%d\n",card[i]);
    return 0;
}