//
//  AOJ10033.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    char inst[4],temp;
    int num,sp[100]={0},from,to,mt,i,j;
    char block[100][1000];
    scanf("%d\n",&num);
    while (1) {
        scanf(" %s",inst);
        if (strcmp(inst,"quit")==0) break;
        if (strcmp(inst,"push")==0) {
            scanf(" %d %c\n",&mt,&temp);
            block[mt-1][sp[mt-1]]=temp;
            sp[mt-1]++;
        } else if (strcmp(inst,"move")==0) {
            scanf("%d %d\n",&from,&to);
            block[to-1][sp[to-1]]=block[from-1][sp[from-1]-1];
            sp[to-1]++;
            sp[from-1]--;
        } else {
            scanf("%d\n",&mt);
            printf("%c\n",block[mt-1][sp[mt-1]-1]);
            sp[mt-1]--;
        }
    }
    return 0;
}