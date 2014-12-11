//
//  AOJ0024.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int i;
    double v,y;
    while (scanf("%lf",&v)!=EOF) {
        i=1;
        y = 10.0*v*v/(14.0*14.0);
        while (5.0*i-5.0<y) i++;
        printf("%d",i);
    }
    return 0;
}