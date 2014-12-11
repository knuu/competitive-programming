//
//  AOJ0079.c
//  
//
//  Created by n_knuu on 2014/03/02.
//
//

#include <stdio.h>

double triangle(double x1,double y1,double x2,double y2,double x3,double y3);

int main(void) {
    double xo,yo,x1,y1,x2,y2,square=0;
    scanf("%lf,%lf\n",&xo,&yo);
    scanf("%lf,%lf\n",&x1,&y1);
    while (scanf("%lf,%lf\n",&x2,&y2)!=EOF) {
        square+=triangle(xo,yo,x1,y1,x2,y2);
        x1=x2;
        y1=y2;
    }
    printf("%.6lf\n",square);
    return 0;
}

double triangle(double x1,double y1,double x2,double y2,double x3,double y3) {
    x2 = (x2-x1)*(y3-y1);
    x3 = (y2-y1)*(x3-x1);
    if (x2>x3) {
        return (x2-x3)/2.0;
    } else {
        return (x3-x2)/2.0;
    }
}