//
//  ABC004C.c
//  
//
//  Created by n_knuu on 2014/02/16.
//
//

#include <stdio.h>
int main(void){
    int a[6] = {1,2,3,4,5,6},n,i,j,temp;
    scanf("%d",&n);
    n=n%30;
    for(i=0;i<n;i++){
        j=i%5;
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
    for(i=0;i<6;i++) printf("%d",a[i]);
    printf("\n");
    return 0;
}