//
//  ITP1-8-B.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <string.h>

int main(void) {
    int i,sum,temp;
    char digit[1002];
    while (1) {
        fgets(digit,sizeof(digit),stdin);
        sscanf(digit,"%d\n",&temp);
        if (temp==0) break;
        sum=0;
        for (i=0; i<strlen(digit)-1; i++) sum+=digit[i]-'0';
        printf("%d\n",sum);
    }
    return 0;
}