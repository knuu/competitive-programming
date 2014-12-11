//
//  AOJ0149.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
char eyetest(double sight);
int main(void) {
    int rc[4]={0},lc[4]={0},i;
    double right,left;
    while (scanf("%lf %lf",&right,&left)!=EOF) {
        rc[eyetest(right)-'A']++;
        lc[eyetest(left)-'A']++;
    }
    for (i=0; i<4; i++) printf("%d %d\n",rc[i],lc[i]);
    return 0;
}

char eyetest(double sight) {
    if (sight<0.2) {
        return 'D';
    } else if (sight<0.6) {
        return 'C';
    } else if (sight<1.1) {
        return 'B';
    } else {
        return 'A';
    }
}