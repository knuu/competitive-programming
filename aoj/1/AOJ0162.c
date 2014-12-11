//
//  AOJ0162.c
//  
//
//  Created by knuu on 2014/05/12.
//
//

#include <stdio.h>
#include <math.h>
int OR3(int num);
int main(void) {
    int m,n;
    while (scanf("%d",&n)!=EOF&&n!=0) {
        scanf("%d",&m);
        printf("%d\n",OR3(m)-OR3(n-1));
    }
    return 0;
}

int OR3(int num) {
    if (num<=0) return 0;
    int i,j,k,count=0;
    for (i=0; pow(2,i)<=num; i++) {
        for (j=0; pow(2,i)*pow(3,j)<=num; j++) {
            for (k=0; pow(2,i)*pow(3,j)*pow(5,k)<=num; k++) {
                count++;
            }
        }
    }
    return count;
}