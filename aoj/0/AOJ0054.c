//
//  AOJ0054.c
//  
//
//  Created by n_knuu on 2014/03/01.
//
//

#include <stdio.h>
int main(void) {
    int a,b,n,sum,i;
    while (scanf("%d %d %d\n",&a,&b,&n)!=EOF) {
        sum=0;
        a=(a%b)*10;
        for (i=0; i<n; i++) {
            sum+=a/b;
            a=(a%b)*10;
        }
        printf("%d\n",sum);
    }
    return 0;
}