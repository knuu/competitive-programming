//
//  AOJ0045.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int price,amount,sum=0,average=0,count=0;
    double temp;
    while (scanf("%d,%d",&price,&amount)!=EOF) {
        sum+=price*amount;
        average+=amount;
        count++;
    }
    average = 1.0 * average/count + 0.5;
    printf("%d\n%d\n",sum,average);
    return 0;
}