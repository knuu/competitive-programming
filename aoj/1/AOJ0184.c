//
//  AOJ0184.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int n,age[7],i,temp;
    while (scanf("%d",&n)!=EOF&&n!=0) {
        for (i=0; i<7; i++) age[i]=0;
        for (i=0; i<n; i++) {
            scanf("%d",&temp);
            temp/=10;
            if (temp>=7) temp=6;
            age[temp]++;
        }
        for (i=0; i<7; i++) printf("%d\n",age[i]);
    }
    return 0;
}