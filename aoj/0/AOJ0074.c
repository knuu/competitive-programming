//
//  AOJ0074.c
//  
//
//  Created by n_knuu on 2014/03/03.
//
//

#include <stdio.h>
int main(void) {
    int hour,minute,second,rest,rh,rm,rs;
    while (1) {
        scanf("%d %d %d\n",&hour,&minute,&second);
        if (hour==-1&&minute==-1&&second==-1) break;
        rest=7200-(hour*3600+minute*60+second);
        rh=rest/3600;
        rest%=3600;
        rm=rest/60;
        rs=rest%60;
        printf("%02d:%02d:%02d\n",rh,rm,rs);
        rest=(7200-(hour*3600+minute*60+second))*3;
        rh=rest/3600;
        rest%=3600;
        rm=rest/60;
        rs=rest%60;
        printf("%02d:%02d:%02d\n",rh,rm,rs);
    }
    return 0;
}