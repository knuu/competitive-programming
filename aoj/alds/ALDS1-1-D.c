//
//  ALDS1-1-D.c
//  
//
//  Created by knuu on 2014/05/01.
//
//

#include <stdio.h>
int main(void) {
    int N,i,min,profit,temp;
    scanf("%d",&N);
    scanf("%d",&temp);
    scanf("%d",&profit);
    min=temp;
    if (min>profit) min=profit;
    profit-=temp;
    for (i=0; i<N-2; i++) {
        scanf("%d",&temp);
        if (temp-min>profit) profit=temp-min;
        if (temp<min) min=temp;
    }
    printf("%d\n",profit);
    return 0;
}