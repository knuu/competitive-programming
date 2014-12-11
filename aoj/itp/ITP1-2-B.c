//
//  ITP1-2-B.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int a,b,c,temp;
    scanf("%d %d %d",&a,&b,&c);
    if (a<b&&b<c) {
        printf("Yes\n");
   } else {
        printf("No\n");
    }
    return 0;
}
