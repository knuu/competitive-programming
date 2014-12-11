//
//  AOJ0016.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int d,theta=0,temp,X,Y;
    double x=0.0,y=0.0;
    while (1) {
        scanf("%d,%d",&d,&temp);
        if (d==0&&temp==0) break;
        x+=d*sin(theta*asin(1)/90);
        y+=d*cos(theta*asin(1)/90);
        theta+=temp;
    }
    X = x;
    Y = y;
    printf("%d\n%d\n",X,Y);
    return 0;
}