//
//  AOJ0177.c
//  
//
//  Created by knuu on 2014/05/12.
//
//

#include <stdio.h>
#include <math.h>
#define rad(x) (x)*M_PI/180.0
int main(void) {
    double theta1,phi1,theta2,phi2,alpha,x1,x2,y1,y2,z1,z2,r=6378.1;
    while (scanf("%lf%lf%lf%lf",&theta1,&phi1,&theta2,&phi2)!=EOF&&(theta1!=-1||theta2!=-1||phi1!=-1||phi2!=-1)) {
        x1=cos(rad(theta1))*cos(rad(phi1));
        x2=cos(rad(theta2))*cos(rad(phi2));
        y1=cos(rad(theta1))*sin(rad(phi1));
        y2=cos(rad(theta2))*sin(rad(phi2));
        z1=sin(rad(theta1));
        z2=sin(rad(theta2));
        alpha=acos(x1*x2+y1*y2+z1*z2);
        printf("%d\n",(int)(r*alpha+0.5));
    }
    return 0;
}