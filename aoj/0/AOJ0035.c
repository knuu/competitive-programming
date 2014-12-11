//
//  AOJ0035.c
//  
//
//  Created by n_knuu on 2014/02/28.
//
//

#include <stdio.h>
#include <math.h>
double theta(double x1,double y1,double x2,double y2);

int main(void){
	int a;
    double xa,ya,xb,yb,xc,yc,xd,yd;
    float alpha;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd)!=EOF) {
    	alpha = theta(xb-xa,yb-ya,xd-xa,yd-ya)+theta(xa-xb,ya-yb,xc-xb,yc-yb)+theta(xd-xc,yd-yc,xb-xc,yb-yc)+theta(xa-xd,ya-yd,xc-xd,yc-yd);
		a = alpha * 1000000;
        if (a==6283185) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

double theta(double x1,double y1,double x2,double y2) {
    return acos(1.0*(x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
}