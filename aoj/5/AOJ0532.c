//
//  AOJ0532.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
int main(void) {
    int hin,min,sin,hout,mout,sout,i,time;
    for (i=0; i<3; i++) {
        scanf("%d%d%d%d%d%d",&hin,&min,&sin,&hout,&mout,&sout);
        time = (hout-hin)*3600+(mout-min)*60+(sout-sin);
        printf("%d %d %d\n",time/3600,(time%3600)/60,(time%3600)%60);
    }
    return 0;
}