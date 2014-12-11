//
//  ITP1-2-A.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int a,b;
    scanf("%d %d",&a,&b);
    if (a>b) {
        printf("a > b\n");
    } else if (a<b) {
        printf("a < b\n");
    } else {
        printf("a == b\n");
    }
    return 0;
}
