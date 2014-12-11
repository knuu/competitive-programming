//
//  AOJ0219.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    int kind[10],i,j,temp,num;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        for (i=0; i<10; i++) kind[i]=0;
        for (i=0; i<num; i++) {
            scanf("%d",&temp);
            kind[temp]++;
        }
        for (i=0; i<10; i++) {
            if (kind[i]==0) {
                printf("-\n");
            } else {
                for (j=0; j<kind[i]; j++) printf("*");
                printf("\n");
            }
        }
    }
    return 0;
}