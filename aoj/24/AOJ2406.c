//
//  AOJ2406.c
//  
//
//  Created by n_knuu on 2014/03/07.
//
//

#include <stdio.h>
int main(void) {
    int num,time,eps,sand[100],i,flag=0;
    scanf("%d %d %d",&num,&time,&eps);
    for (i=0; i<num; i++) {
        scanf("%d",&sand[i]);
        if (flag==0) {
            if (sand[i]>=time&&sand[i]-time<=eps) {
                flag=i+1;
            } else if (sand[i]<time) {
                if (time%sand[i]<=eps||(((time/sand[i])+1)*sand[i])%time<=eps) {
                    flag=i+1;
                }
            }
        }
    }
    if (flag!=0) {
        printf("%d\n",flag);
    } else {
        printf("-1\n");
    }
    return 0;
}