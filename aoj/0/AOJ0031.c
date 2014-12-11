//
//  AOJ0031.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int m,w[10],temp,i,j;
    while (scanf("%d",&m)!=EOF) {
        for (i=0;i<10;i++) w[i]=0;
        for (i=0;i<10;i++){
            w[i]=m%2;
            m/=2;
            if (m==0) break;
        }
        for (j=0;j<=i;j++) {
            if (w[j]!=0) {
            	temp = pow(2,j);
            	printf("%d",temp);
            	if (j!=i) {
            		printf(" ");
            	}
            }
        }
		printf("\n");
    }
    return 0;
}