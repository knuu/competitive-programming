//
//  AOJ0075.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int num[100],i,j;
    float weight,height,bmi[100];
    while(scanf("%d,%f,%f",&num[i],&weight,&height)!=EOF) {
        bmi[i] = weight/(height*height);
        i++;
    }
    for(j=0;j<i;j++) {
        if(bmi[j]>=25) printf("%d\n",num[j]);
    }
    return 0;
}