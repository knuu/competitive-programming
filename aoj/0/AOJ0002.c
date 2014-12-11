//
//  AOJ0002.c
//  
//
//  Created by n_knuu on 2014/02/16.
//
//

#include <stdio.h>
int main(void){
    int a,b,i=0,j,k,d,sum[200];
    while(scanf("%d %d",&a,&b)!=-1){
        sum[i] = a+b;
        i++;
    }
    for(j=0;j<i;j++){
        d=10;
        for(k=1;;k++){
            if(sum[j]<d){
                printf("%d\n",k);
                break;
            } else {
                d*=10;
            }
        }
    }
    return 0;
}