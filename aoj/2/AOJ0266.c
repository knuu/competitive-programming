//
//  AOJ0266.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int city[6][2]={{1,2},{-1,3},{1,-1},{4,5},{5,2},{2,1}},i,now;
    char route[100];
    while (1) {
        scanf(" %s\n",route);
        if (route[0]=='#') break;
        now=0;
        for (i=0; i<strlen(route)&&now!=-1; i++) {
            now=city[now][route[i]-'0'];
        }
        if (now==5) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}