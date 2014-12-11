//
//  AOJ0511.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
int main(void) {
    int num[31]={0},i,temp;
    for (i=0; i<28; i++) {
        scanf("%d\n",&temp);
        num[temp]++;
    }
    for (i=1; i<=30; i++) {
        if (num[i]==0) printf("%d\n",i);
    }
    return 0;
}