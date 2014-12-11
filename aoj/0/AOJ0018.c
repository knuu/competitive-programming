//
//  AOJ0018.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int num[5],i,j,temp;
    for(i=0;i<5;i++) scanf("%d",&num[i]);
    for(i=0;i<5;i++){
        for(j=0;j<4-i;j++){
            if(num[j]<num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(i=0;i<5;i++) {
        if((i+1)%5==0) {
            printf("%d\n",num[i]);
        } else{
            printf("%d ",num[i]);
        }
    }
    return 0;
}