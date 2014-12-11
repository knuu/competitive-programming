//
//  AOJ0057.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int ans[100],temp,i=0,j;
    while(scanf("%d",&temp)!=EOF) {
        ans[i] =temp*(temp+1)/2 + 1;
        i++;
    }
    for(j=0;j<i;j++) printf("%d\n",ans[j]);
    return 0;
}