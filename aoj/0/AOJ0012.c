//
//  AOJ0012.c
//  
//
//  Created by n_knuu on 2014/02/28.
//
//

#include <stdio.h>
int main(void) {
    double x1,y1,x2,y2,x3,y3,xp,yp,k,l;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n",&x1,&y1,&x2,&y2,&x3,&y3,&xp,&yp)!=EOF) {
        k=((xp-x1)*(y3-y1)-(yp-y1)*(x3-x1))/((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
        l=((yp-y1)*(x2-x1)-(xp-x1)*(y2-y1))/((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
        if (k>0.0&&l>0.0&&k+l<1.0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}