//
//  AOJ0021.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int n,i;
    float x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if ((y2-y1)*(x4-x3)-(x2-x1)*(y4-y3)==0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}