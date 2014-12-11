//
//  AOJ10021.c
//  
//
//  Created by n_knuu on 2014/03/04.
//
//

#include <stdio.h>
int main(void) {
    int num,i;
    char top[21],temp[21];
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        if (i==0) {
            scanf("%s\n",top);
        } else {
            scanf("%s\n",temp);
            if (strcmp(top,temp)>0) strcpy(top, temp);
        }
    }
    printf("%s\n",top);
    return 0;
}