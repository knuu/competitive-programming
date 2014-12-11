//
//  AOJ10024.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    double x1,y1,x2,y2;
    scanf("%lf %lf %lf %lf\n",&x1,&y1,&x2,&y2);
    printf("%.8lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    return 0;
}