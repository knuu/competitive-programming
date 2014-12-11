//
//  AOJ0167.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int a[101],num,i,j,temp,count;
    while (scanf("%d",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) scanf("%d",&a[i]);
        count=0;
        for (i=0; i<num-1; i++) {
            for (j=0; j<num-1-i; j++) {
                if (a[j]>a[j+1]) {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}