//
//  ITP1-3-C.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int x,y,temp;
    while (1) {
        scanf("%d %d",&x,&y);
        if (x==0&&y==0) break;
        if (x<y) {
            printf("%d %d\n",x,y);
        } else {
            printf("%d %d\n",y,x);
        }
    }
    return 0;
}