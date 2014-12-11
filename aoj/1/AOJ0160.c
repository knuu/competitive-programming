//
//  AOJ0160.c
//  
//
//  Created by n_knuu on 2014/04/11.
//
//

#include <stdio.h>
int main(void) {
    int sum,num,i,x,y,h,w;
    while (scanf("%d",&num)!=EOF&&num!=0) {
        sum=0;
        for (i=0; i<num; i++) {
            scanf("%d%d%d%d",&x,&y,&h,&w);
            x+=y+h;
            if (x<=60&&w<=2) {
                sum+=600;
            } else if (x<=80&&w<=5) {
                sum+=800;
            } else if (x<=100&&w<=10) {
                sum+=1000;
            } else if (x<=120&&w<=15) {
                sum+=1200;
            } else if (x<=140&&w<=20) {
                sum+=1400;
            } else if (x<=160&&w<=25) {
                sum+=1600;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}