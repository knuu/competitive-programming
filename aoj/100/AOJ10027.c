//
//  AOJ10027.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int num,tarou=0,hanako=0,i;
    char t[100],h[100];
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        scanf("%s %s\n",t,h);
        if (strcmp(t,h)>0) {
            tarou+=3;
        } else if (strcmp(t,h)<0) {
            hanako+=3;
        } else {
            tarou++;
            hanako++;
        }
    }
    printf("%d %d\n",tarou,hanako);
    return 0;
}