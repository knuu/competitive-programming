//
//  AOJ0058.c
//  
//
//  Created by n_knuu on 2014/02/26.
//
//

#include <stdio.h>
int main(void) {
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF) {
        if ((x2-x1)*(x4-x3)+(y2-y1)*(y4-y3)==0.0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}