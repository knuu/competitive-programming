//
//  AOJ1009.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF) {
        while (1) {
            if (a>b) {
                a%=b;
                if (a==0) {
                    printf("%d\n",b);
                    break;
                }
            } else {
                b%=a;
                if (b==0) {
                    printf("%d\n",a);
                    break;
                }
            }
        }
    }
    return 0;
}