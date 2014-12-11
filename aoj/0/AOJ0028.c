//
//  AOJ0028.c
//  
//
//  Created by n_knuu on 2014/02/22.
//
//

#include <stdio.h>
int main(void){
    int count[100]={0},temp,max=0;
    while(scanf("%d",&temp)!=EOF) count[temp-1]++;
    for(temp=0;temp<100;temp++){
        if (count[temp]>max) max=count[temp];
    }
    for(temp=0;temp<100;temp++) {
        if (count[temp]==max) printf("%d\n",temp+1);
    }
    return 0;
}