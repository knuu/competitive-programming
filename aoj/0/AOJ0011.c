//
//  AOJ0011.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int w,n,i,a,b,temp;
    scanf("%d %d",&w,&n);
    int num[w+1];
    for(i=1;i<=w;i++) num[i]=i;
    for(i=0;i<n;i++){
        scanf("%d,%d",&a,&b);
        temp=num[a];
        num[a]=num[b];
        num[b]=temp;
    }
    for(i=1;i<=w;i++) printf("%d\n",num[i]);
    return 0;
}