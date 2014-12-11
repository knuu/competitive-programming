//
//  AOJ0521.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
int main(void) {
    int price,change,coin,i;
    while (1) {
        scanf("%d",&price);
        if (price==0) break;
        coin=0;
        change=1000-price;
        while (change!=0) {
            if (change>=500) {
                coin++;
                change%=500;
            } else if (change>=100) {
                coin+=change/100;
                change%=100;
            } else if (change>=50) {
                coin++;
                change%=50;
            } else if (change>=10) {
                coin+=change/10;
                change%=10;
            } else if (change>=5) {
                coin++;
                change%=5;
            } else {
                coin+=change;
                break;
            }
        }
        printf("%d\n",coin);
    }
    return 0;
}