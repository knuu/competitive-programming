//
//  AOJ0549.c
//  
//
//  Created by n_knuu on 2014/03/14.
//
//

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int num,day,move,town=0,temp,road[100000]={0},sum=0,i;
    scanf("%d %d",&num,&day);
    for (i=0; i<num-1; i++) {
        scanf("%d",&temp);
        road[i+1]=road[i]+temp;
    }
    for (i=0; i<day; i++) {
        scanf("%d",&move);
        sum+=abs(road[town+move]-road[town]);
        sum%=100000;
        town+=move;
    }
    printf("%d\n",sum);
    return 0;
}