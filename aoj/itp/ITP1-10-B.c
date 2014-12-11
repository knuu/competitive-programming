//
//  ITP1-10-B.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    double a,b,c,C,radC;
    scanf("%lf %lf %lf",&a,&b,&C);
    radC=C*M_PI/180;
    printf("%.8lf %.8lf %.8lf",a*b*sin(radC)/2.0,a+b+sqrt(a*a+b*b-2*a*b*cos(radC)),b*sin(radC));
    return 0;
}