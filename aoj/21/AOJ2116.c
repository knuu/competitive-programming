//
//  AOJ2116.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>
int main(void) {
    int price,money,change;
    while (1) {
        scanf("%d %d\n",&price,&money);
        if (price==0&&money==0) break;
        change=money-price;
        printf("%d %d %d\n",(change%500)/100,(change%1000)/500,change/1000);
    }
    return 0;
}