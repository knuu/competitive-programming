//
//  AOJ0161.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>
int main(void) {
    int num,c1,m1,s1,m2,s2,m3,s3,m4,s4,tempt,cf,tf,cs,ts,cb,tb,cl,tl,i;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        tf=14400,ts=14400,tb=-1,tl=-1;
        for (i=0; i<num; i++) {
            scanf("%d %d %d %d %d %d %d %d %d",&c1,&m1,&s1,&m2,&s2,&m3,&s3,&m4,&s4);
            tempt=(m1+m2+m3+m4)*60+s1+s2+s3+s4;
            if (tempt<tf) {
                cs=cf;
                ts=tf;
                cf=c1;
                tf=tempt;
            } else if (tempt<ts) {
                cs=c1;
                ts=tempt;
            }
            if (tempt>tl) {
                cb=cl;
                tb=tl;
                cl=c1;
                tl=tempt;
            } else if (tempt>tb) {
                cb=c1;
                tb=tempt;
            }
        }
        printf("%d\n%d\n%d\n",cf,cs,cb);
    }
    return 0;
}