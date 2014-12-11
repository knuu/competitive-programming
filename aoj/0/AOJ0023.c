//
//  AOJ0023.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int n,i;
    float xa,ya,ra,xb,yb,rb,dif,sum,dis;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%f %f %f %f %f %f",&xa,&ya,&ra,&xb,&yb,&rb);
        dis=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
        dif=(ra-rb)*(ra-rb);
        sum=(ra+rb)*(ra+rb);
        if (dis<dif) {
            if (ra>rb) {
                printf("2\n");
            } else {
                printf("-2\n");
            }
        } else if (dis>sum) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}