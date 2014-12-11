//
//  AOJ0080.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
int main(void){
    int q;
    double x;
    while (1) {
        scanf("%d",&q);
        if (q==-1) break;
        x = q/2.0;
        while (x*x*x-q<=-0.00001*q||0.00001*q<=x*x*x-q) {
            x = x - (x*x*x-q)/(3*x*x);
        }
        printf("%lf\n",x);
    }
    return 0;
}