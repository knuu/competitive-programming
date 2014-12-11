//
//  ALDS1-2-A.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int a[101],length,i,j,count=0,temp;
    scanf("%d",&length);
    for (i=0; i<length; i++) scanf("%d",&a[i]);
    for (i=0; i<length; i++) {
        for (j=length-1; j>i; j--) {
            if (a[j]<a[j-1]) {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                count++;
            }
        }
    }
    for (i=0; i<length; i++) {
        if (i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",count);
    return 0;
}