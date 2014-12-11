//
//  AOJ0216.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int water,charge;
    while (1) {
        scanf("%d",&water);
        if (water==-1) break;
        charge=1150;
        water-=10;
        if (water>0) {
            if (water<=10) {
                charge+=water*125;
            } else {
                charge+=10*125;
            }
            water-=10;
        }
        if (water>0) {
            if (water<=10) {
                charge+=water*140;
            } else {
                charge+=10*140;
            }
            water-=10;
        }
        if (water>0) charge+=water*160;
        printf("%d\n",4280-charge);
    }
    return 0;
}