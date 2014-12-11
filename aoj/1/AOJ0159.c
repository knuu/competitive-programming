//
//  AOJ0159.c
//  
//
//  Created by knuu on 2014/05/12.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int num,id,i,tempid;
    double height,weight,BMI,best;
    while (scanf("%d",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) {
            scanf("%d%lf%lf",&tempid,&height,&weight);
            height/=100.0;
            BMI=weight/(height*height);
            if (i==0) {
                id = tempid;
                best = BMI;
            } else {
                if (fabs(BMI-22.0)<fabs(best-22.0)) {
                    best=BMI;
                    id = tempid;
                } else if ((abs(BMI-22.0)==abs(best-22.0))&&tempid<id) {
                    id = tempid;
                }
            }
        }
        printf("%d\n",id);
    }
    return 0;
}