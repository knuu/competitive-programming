//
//  AOJ0081.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
int main(void){
    double x1,y1,x2,y2,xq,yq,t;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf",&x1,&y1,&x2,&y2,&xq,&yq)!=EOF) {
        t=((x2-x1)*(xq-x1)+(y2-y1)*(yq-y1))/((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%lf %lf\n",2*(1-t)*x1+2*t*x2-xq,2*(1-t)*y1+2*t*y2-yq);
    }
    return 0;
}