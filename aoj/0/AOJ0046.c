//
//  AOJ0046.c
//  
//
//  Created by n_knuu on 2014/02/22.
//
//

#include <stdio.h>
int main(void){
    float max,min,temp;
    scanf("%f",&max);
    min = max;
    while(scanf("%f",&temp)!=EOF){
        if(temp > max) {
            max = temp;
        } else if (temp < min) {
            min = temp;
        }
    }
    printf("%f",max-min);
    return 0;
}