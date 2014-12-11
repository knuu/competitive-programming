//
//  AOJ2204.c
//  
//
//  Created by knuu on 2014/05/12.
//
//

#include <stdio.h>
int main(void) {
    int num,s=0,temp,i,j,max,min;
    while (scanf("%d",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) {
            s=0;
            for (j=0; j<5; j++) {
                scanf("%d",&temp);
                s+=temp;
            }
            if (i==0) {
                max=s,min=s;
            } else if (s>max) {
                max=s;
            } else if (s<min) {
                min=s;
            }
        }
        printf("%d %d\n",max,min);
    }
    return 0;
}