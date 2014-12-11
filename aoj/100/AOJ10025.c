//
//  AOJ10025.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int a,b,C;
    scanf("%d %d %d\n",&a,&b,&C);
    printf("%.8lf\n%.8lf\n%.8lf\n",a*b*sin(C*M_PI/180.0)/2,a+b+sqrt(a*a+b*b-2.0*a*b*cos(C*M_PI/180.0)),b*sin(C*M_PI/180.0));
    return 0;
}