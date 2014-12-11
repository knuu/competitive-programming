//
//  ITP1-7-A.c
//  
//
//  Created by n_knuu on 2014/03/14.
//
//

#include <stdio.h>
int main(void) {
    int m,f,r,score;
    while (1) {
        scanf("%d %d %d",&m,&f,&r);
        score=m+f;
        if (m==-1&&f==-1&&r==-1) break;
        if (m==-1||f==-1) {
            printf("F\n");
        } else if (score>=80) {
            printf("A\n");
        } else if (score>=65) {
            printf("B\n");
        } else if (score>=50||(score>=30&&r>=50)) {
            printf("C\n");
        } else if (score>=30) {
            printf("D\n");
        } else {
            printf("F\n");
        }
    }
    return 0;
}