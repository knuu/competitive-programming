//
//  AOJ1019.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    int num,kind,temp,i;
    while (1) {
        scanf("%d %d\n",&num,&kind);
        if (num==0&&kind==0) break;
        int bk[kind],flag=0;
        for (i=0; i<kind; i++) scanf("%d",&bk[i]);
        for (i=0; i<num*kind; i++) {
            scanf("%d",&temp);
            bk[i%kind]-=temp;
        }
        for (i=0; i<kind; i++) {
            if (bk[i%kind]<0) flag=1;
        }
        if (flag==0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}