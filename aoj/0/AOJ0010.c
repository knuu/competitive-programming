//
//  AOJ0010.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
#include <math.h>

double round(double x);

int main (void) {
    int n,i;
    double x1,y1,x2,y2,x3,y3,px,py,r;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
        px=(x1*x1*(y2-y3)/2.0+x2*x2*(y3-y1)/2.0+x3*x3*(y1-y2)/2.0-(y2-y1)*(y3-y2)*(y1-y3))/((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
        if (y1!=y2) {
            py=-(x2-x1)*(px-(x1+x2)/2.0)/(y2-y1)+(y1+y2)/2.0;
        } else {
            py=-(x3-x1)*(px-(x1+x3)/2.0)/(y3-y1)+(y1+y3)/2.0;
        }
        r = sqrt((px-x1)*(px-x1)+(py-y1)*(py-y1));
        px = round(px);
        py = round(py);
        r = round(r);
        printf("%.3lf %.3lf %.3lf\n",px,py,r);
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