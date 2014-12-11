//
//  AOJ0567.c
//  
//
//  Created by n_knuu on 2014/04/12.
//
//

#include <stdio.h>
int main(void) {
    int num,a,b,c,d[10001],i,j,temp,cal,price;
    scanf("%d%d%d%d",&num,&a,&b,&c);
    for (i=0; i<num; i++) scanf("%d",&d[i]);
    for (i=0; i<num-1; i++) {
        for (j=0; j<num-1-i; j++) {
            if (d[j]<d[j+1]) {
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }
    cal=c,price=a;
    for (i=0; i<num; i++) {
        if (1.0*cal/price<1.0*(cal+d[i])/(price+b)) {
            cal+=d[i];
            price+=b;
        } else {
            break;
        }
    }
    printf("%d\n",cal/price);
    return 0;
}