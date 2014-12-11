//
//  ABC004D.c
//  
//
//  Created by n_knuu on 2014/02/16.
//
//

#include <stdio.h>
int main(void){
    int c[3],sum=0,i,m,n;
    scanf("%d %d %d",&c[0],&c[1],&c[2]);
    for(i=0;i<3;i++){
        if (c[i]%2==0) {
            m=c[i]/2;
            n=m-1;
            sum+=m*(m+1)/2+n*m/2;
        } else {
            m=(c[i]-1)/2;
            sum+=m*(m+1);
        }
    }
    printf("%d\n",sum);
    return 0;
}