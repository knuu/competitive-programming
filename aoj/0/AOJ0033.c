//
//  AOJ0033.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void){
    int n,A,B,C,i,j;
    scanf("%d",&n);
    for (j=0;j<n;j++) {
    	B=0;
    	C=0;
        for (i=0; i<10; i++) {
        	scanf("%d",&A);
            if ((B<A&&A<C)||(C<=B&&B<A)) {
                B=A;
            } else if ((C<A&&A<B)||(B<C&&C<A)) {
                C=A;
            } else {
                printf("NO\n");
                break;
            }
            if (i==9) printf("YES\n");
        }
    }
    return 0;
}