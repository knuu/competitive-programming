//
//  AOJ2018.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int num,first,percent,gold[1000],sum,i;
    while (1) {
        scanf("%d %d %d",&num,&first,&percent);
        if (num==0&&first==0&&percent==0) break;
        sum=0;
        for (i=0; i<num; i++) {
            scanf("%d",&gold[i]);
            sum+=gold[i];
        }
        if (gold[first-1]!=0) {
            printf("%d\n",sum*(100-percent)/gold[first-1]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}