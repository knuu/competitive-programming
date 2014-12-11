//
//  AOJ0272.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int num,my[40000],her[40000],i,j,temp,win,flag;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        for (i=0; i<num; i++) scanf("%d",&my[i]);
        for (i=0; i<num; i++) scanf("%d",&her[i]);
        for (i=0; i<num; i++) {
            for (j=0; j<num-i-1; j++) {
                if (my[j]<my[j+1]) {
                    temp=my[j];
                    my[j]=my[j+1];
                    my[j+1]=temp;
                }
            }
        }
        for (i=0; i<num; i++) {
            for (j=0; j<num-i-1; j++) {
                if (her[j]<her[j+1]) {
                    temp=her[j];
                    her[j]=her[j+1];
                    her[j+1]=temp;
                }
            }
        }
        win=0,flag=0;
        for (i=0; i<num; i++) {
            if (my[i]>her[i]) win++;
            if (win>=(i+1)/2+1) {
                flag=i+1;
                break;
            }
        }
        if (flag==0) {
            printf("NA\n");
        } else {
            printf("%d\n",flag);
        }
    }
    return 0;
}