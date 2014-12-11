//
//  AOJ1135.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int num,i,j,k,fund,year,kind,type,fee,interest,max,temp;
    double rate;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%d %d %d",&fund,&year,&kind);
        max=0;
        for (j=0; j<kind; j++) {
            scanf("%d %lf %d",&type,&rate,&fee);
            temp=fund;
            if (type==0) {
                interest=0;
                for (k=0; k<year; k++) {
                    interest+=temp*rate;
                    temp-=fee;
                }
                if (temp+interest>max) max=temp+interest;
            } else {
                for (k=0; k<year; k++) temp=temp*rate-fee;
                if (temp>max) max=temp;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}