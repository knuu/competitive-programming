//
//  AOJ0197.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int x,y,count,temp;
    while (scanf("%d%d",&x,&y)!=EOF&&(x!=0||y!=0)) {
        if (x<y) {
            temp=x;
            x=y;
            y=temp;
        }
        count=0;
        while (y!=0) {
            x%=y;
            temp=x;
            x=y;
            y=temp;
            count++;
        }
        printf("%d %d\n",x,count);
    }
    return 0;
}