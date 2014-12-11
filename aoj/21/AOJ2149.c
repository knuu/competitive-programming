//
//  AOJ2149.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int makerand(int a, int b, int c, int x);
int main(void) {
    int num,a,b,c,rand,i,reel[100],sp;
    while (1) {
        scanf("%d %d %d %d %d",&num,&a,&b,&c,&rand);
        if (num==0&&a==0&&b==0&&c==0&&rand==0) break;
        for (i=0; i<num; i++) scanf("%d",&reel[i]);
        sp=0;
        for (i=0; i<num; i++) {
            if (reel[i]>=c) break;
        }
        if (i!=num) {
            printf("-1\n");
            continue;
        }
        if (rand==reel[0]) {
            sp++;
        }
        for (i=1; i<=10000; i++) {
            if (sp>=num-1&&reel[sp]==makerand(a,b,c,rand)) break;
        	rand=makerand(a,b,c,rand);
            if (rand==reel[sp]) sp++;
        }
        if (i==10001) {
            printf("-1\n");
        } else {
            printf("%d\n",i);
        }
    }
    return 0;
}

int makerand(int a, int b, int c, int x) {
    return (a*x+b)%c;
}