//
//  ARC018-1.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    double height,BMI;
    scanf("%lf %lf",&height,&BMI);
    printf("%.3lf\n",BMI*height*height/10000.0);
    return 0;
}