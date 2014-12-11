//
//  AOJ0506.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int num,i,j,count;
    char digit[100000],now,new[100000],temp[100000];
    while (scanf("%d\n",&num)!=EOF&&num) {
        scanf("%s\n",digit);
        for (i=0; i<num; i++) {
        	memset(new,'\0',sizeof(new));
            for (j=0; j<strlen(digit); j++) {
                if (j==0) {
                    now=digit[0];
                    count=1;
                } else {
                    if (digit[j]!=now) {
                        sprintf(temp,"%d%c",count,now);
                        strcat(new,temp);
                        now=digit[j];
                        count=1;
                    } else {
                        count++;
                    }
                }
            }
            sprintf(temp,"%d%c",count,now);
            strcat(new,temp);
            strcpy(digit,new);
        }
        printf("%s\n",digit);
    }
    return 0;
}