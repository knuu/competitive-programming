//
//  AOJ0019.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    long long n,i,ans=1;
    scanf("%d",&n);
    for(i=n;i>1;i--) ans*=i;
    printf("%lld\n",ans);
    return 0;
}