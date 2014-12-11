//
//  AOJ2544.c
//  
//
//  Created by knuu on 2014/05/18.
//
//

#include <stdio.h>
int main(void) {
    int num,que,i,year[51];
    char name[51][31];
    scanf("%d %d",&num,&que);
    for (i=0; i<num; i++) {
        scanf("%d %s",&year[i],name[i]);
    }
    i=0;
    while (year[i]<=que&&i<num) {
        i++;
    }
    if (i==0) {
        printf("kogakubu10gokan\n");
    } else {
        printf("%s\n",name[i-1]);
    }
    return 0;
}