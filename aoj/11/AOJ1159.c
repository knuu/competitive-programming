//
//  AOJ1159.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int num,peb,i;
    while (1) {
        scanf("%d %d",&num,&peb);
        if (num==0&&peb==0) break;
        int cand[50]={0},bowl=0,flag;
        while (1) {
            if (peb>0) {
                cand[bowl]++;
                peb--;
            } else {
                peb=cand[bowl];
                cand[bowl]=0;
            }
            flag=0;
            if (peb==0&&cand[bowl]!=0) {
                flag=1;
                for (i=0; i<num; i++) {
                    if (i!=bowl&&cand[i]!=0) {
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==1) {
                break;
            } else {
                if (bowl==num-1) {
                    bowl=0;
                } else {
                    bowl++;
                }
            }
        }
        printf("%d\n",bowl);
    }
    return 0;
}