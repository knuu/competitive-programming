//
//  AOJ0055.c
//  
//
//  Created by n_knuu on 2014/03/01.
//
//

#include <stdio.h>
int main(void) {
    int i;
    double a,sum;
    while (scanf("%lf",&a)!=EOF) {
        sum=a;
        for (i=1; i<10; i++) {
            if (i%2==1) {
                a*=2.0;
            } else {
                a/=3.0;
            }
            sum+=a;
        }
        printf("%.8lf\n",sum);
    }
    return 0;
}