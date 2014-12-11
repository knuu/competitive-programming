//
//  AOJ0044.c
//  
//
//  Created by n_knuu on 2014/02/26.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int n,i,j,flag;
    while (scanf("%d",&n)!=EOF) {
        for(i=n-1;;i--) {
            flag = 1;
            for (j=2; j*1.0<=sqrt(i); j+=2) {
                if (i%j==0) {
                    flag=0;
                    break;
                }
                if (j==2) j--;
            }
            if (flag==1) {
                printf("%d ",i);
                break;
            }
        }
        for(i=n+1;;i++) {
            flag = 1;
            for (j=2; j*1.0<=sqrt(i); j+=2) {
                if (i%j==0) {
                    flag=0;
                    break;
                }
                if (j==2) j--;
            }
            if (flag==1) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}