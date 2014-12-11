//
//  AOJ0052.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int count[100]={0},temp,five,i,j;
    for(i=0;;i++){
    	five=5;
        scanf("%d",&temp);
        if(temp==0) break;
        while(1) {
            if (temp>=five) {
                count[i]+=temp / five;
            } else {
                break;
            }
            five*=5;
        }
    }
    for(j=0;j<i;j++) printf("%d\n",count[j]);
    return 0;
}