//
//  AOJ0103.c
//  
//
//  Created by n_knuu on 2014/02/27.
//
//

#include <stdio.h>
int main(void) {
    int n,out,first,second,third,score,i;
    char event[7];
    scanf("%d\n",&n);
    for (i=0; i<n; i++) {
        first=0,second=0,third=0,score=0,out=0;
        while (1) {
            scanf("%s\n",event);
            if (event[0]=='O') {
                out++;
                if (out==3) break;
            }
            if (event[0]=='H') {
                if (event[1]=='I') {
                    if (third==1) {
                        score++;
                        third--;
                    }
                    if (second==1) {
                        third++;
                        second--;
                    }
                    if (first==1) {
                        second++;
                        first--;
                    }
                    first++;
                } else {
                    score+=first+second+third+1;
                    first=0,second=0,third=0;
                }
            }
        }
        printf("%d\n",score);
    }
    return 0;
}