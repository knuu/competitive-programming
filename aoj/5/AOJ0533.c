//
//  AOJ0533.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
int main(void) {
    int i,temp,w1=0,w2=0,w3=0,k1=0,k2=0,k3=0;
    for (i=0; i<10; i++) {
        scanf("%d",&temp);
        if (temp>w1) {
            w3=w2;
            w2=w1;
            w1=temp;
        } else if (temp>w2) {
            w3=w2;
            w2=temp;
        } else if (temp>w3) {
            w3=temp;
        }
    }
    printf("%d ",w1+w2+w3);
    for (i=0; i<10; i++) {
        scanf("%d",&temp);
        if (temp>k1) {
            k3=k2;
            k2=k1;
            k1=temp;
        } else if (temp>k2) {
            k3=k2;
            k2=temp;
        } else if (temp>k3) {
            k3=temp;
        }
    }
    printf("%d\n",k1+k2+k3);
    return 0;
}