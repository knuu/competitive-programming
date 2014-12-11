//
//  AOJ0004.c
//  
//
//  Created by n_knuu on 2014/02/28.
//
//

#include <stdio.h>

double round(double x);

int main(void) {
    int temp;
    double a,b,c,d,e,f,x,y;
    while (scanf("%lf %lf %lf %lf %lf %lf\n",&a,&b,&c,&d,&e,&f)!=EOF) {
        x = 1.0*(c*e-b*f)/(a*e-b*d);
        y = 1.0*(a*f-c*d)/(a*e-b*d);
        printf("%.3lf %.3lf\n",round(x),round(y));
    }
    return 0;
}

double round(double x) {
    int temp;
    if (x>=0) {
        temp = x*1000+0.5;
        return 1.0*temp/1000;
    } else {
        temp = x*1000-0.5;
        return 1.0*temp/1000;
    }
}