//
//  AOJ0593.c
//  
//
//  Created by n_knuu on 2014/02/15.
//
//

#include <stdio.h>
int main(void){
    int n,m,i,j,max;
    scanf("%d %d",&n,&m);
    int a[n],b[m],count[n];
    for(i=0;i<n;i++) count[i]=0;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<m;i++) scanf("%d",&b[i]);

    for(i=0;i<m;i++){
        for(j=0;;j++){
            if (b[i]>=a[j]) {
                count[j]++;
                break;
            }
        }
    }
    max=1;
    for(i=0;i<n-1;i++){
        if (count[max-1]<count[i+1]) max=i+2;
    }
    printf("%d\n",max);
    return 0;
}