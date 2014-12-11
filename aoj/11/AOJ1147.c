//
//  AOJ1147.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int num,score,sum,min,max,i;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        sum=0;
        for (i=0; i<num; i++) {
            scanf("%d",&score);
            sum+=score;
            if (i==0) {
                max=score;
                min=score;
            } else if (score>max) {
                max=score;
            } else if (score<min){
                min=score;
            }
        }
        printf("%d\n",(sum-max-min)/(num-2));
    }
    return 0;
}