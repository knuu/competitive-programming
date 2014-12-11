//
//  AOJ0241.c
//  
//
//  Created by knuu on 2014/04/28.
//
//

#include <stdio.h>
int main(void) {
    int num,i,x1,x2,y1,y2,z1,z2,w1,w2;
    while (scanf("%d",&num)!=EOF&&num!=0) {
        for (i=0; i<num; i++) {
            scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&w1,&x2,&y2,&z2,&w2);
            printf("%d %d %d %d\n",x1*x2-y1*y2-z1*z2-w1*w2,x1*y2+y1*x2+z1*w2-w1*z2,x1*z2+z1*x2-y1*w2+w1*y2,x1*w2+w1*x2+y1*z2-z1*y2);
        }
    }
    return 0;
}