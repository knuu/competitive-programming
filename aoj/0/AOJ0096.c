//
//  AOJ0096.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    long int ans[50],temp,n,i=0,j;
    while(scanf("%d",&n)!=EOF){
        temp=0;
        if(n<=1000){
            ans[i]=(n+3)*(n+2)*(n+1)/6;
        } else if (n<=2000) {
            for(j=0;j<n-1000;j++) temp+=2*(j+2)*(j+1);
            ans[i]=(n+3)*(n+2)*(n+1)/6 - temp;
        } else if(n<3000){
        	for(j=0;j<3000-n;j++) temp+=2*(j+2)*(j+1);
            ans[i] = (4003-n)*(4002-n)*(4001-n)/6 - temp;
        } else {
            ans[i]= (4003-n)*(4002-n)*(4001-n)/6;
        }
        i++;
    }
    for(j=0;j<i;j++) printf("%d\n",ans[j]);
    return 0;
}