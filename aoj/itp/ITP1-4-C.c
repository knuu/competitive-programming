//
//  ITP1-4-C.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int a,b;
    char op;
    while (1) {
        scanf("%d %c %d",&a,&op,&b);
        if (op == '?') break;
        if (op == '+') {
            printf("%d\n",a+b);
        } else if (op == '-') {
            printf("%d\n",a-b);
        } else if (op == '*') {
            printf("%d\n",a*b);
        } else if (op == '/') {
            printf("%d\n",a/b);
        }
    }
    return 0;
}