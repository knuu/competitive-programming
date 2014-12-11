//
//  ALDS1-1-B.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    int a,b,temp;
    scanf("%d %d",&a,&b);
    if (b>a) {
        temp=b;
        b=a;
        a=temp;
    }
    while (1) {
        temp=a%b;
        if (temp==0) {
            printf("%d\n",b);
            break;
        } else {
            a=b,b=temp;
        }
    }
    return 0;
}