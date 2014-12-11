//
//  AOJ0218.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
int main(void) {
    int num,pm,pe,pj,i,ave;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        for (i=0; i<num; i++) {
            scanf("%d %d %d",&pm,&pe,&pj);
            ave=(pm+pe+pj)/3;
            if (pm==100||pe==100||pj==100||(pm+pe)/2>=90||ave>=80) {
                printf("A\n");
            } else if (ave>=70||(ave>=50&&(pm>=80||pe>=80))) {
                printf("B\n");
            } else {
                printf("C\n");
            }
        }
    }
    return 0;
}