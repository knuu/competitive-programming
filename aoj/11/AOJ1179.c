//
//  AOJ1179.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int num,year,month,day,i,count,leap,last;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        count=0;
        scanf("%d %d %d",&year,&month,&day);
        while (year!=1000) {
            if (month==1&&day==1) {
                leap=(999-year)/3+1;
                count+=leap*20*10+(1000-year-leap)*(20*5+19*5);
                year=1000;
            } else if (day==1) {
                last=11-month;
                if (year%3==0) {
                    count+=last*20;
                } else {
                    if (month%2==0) {
                        count+=(last/2+1)*19+(last/2)*20;
                    } else {
                        count+=(last/2)*(19+20);
                    }
                }
                month=1,year++;
            } else {
                last=10-month;
                if (year%3==0) {
                    count+=(21-day)+last*20;
                } else {
                    if (month%2==0) {
                        count+=20-day+(last/2)*(19+20);
                    } else {
                        count+=21-day+(last/2+1)*19+(last/2)*20;
                    }
                }
                month=1,day=1,year++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}