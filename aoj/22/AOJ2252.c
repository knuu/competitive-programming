//
//  AOJ2252.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
#include <string.h>

int key(int string);
int  main(void) {
    char string[32];
    int i,hand,count,temp;
    while (1) {
        scanf("%s\n",string);
        if (string[0]=='#') break;
        for (i=0; i<strlen(string); i++) {
            temp=key(string[i]);
            if (i==0) {
                hand=temp;
                count=0;
            } else if ((hand==0&&temp==1)||(hand==1&&temp==0)) {
                count++;
                hand=temp;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

int key(int string) {
    if (string=='y'||string=='u'||string=='i'||string=='o'||string=='p'||string=='h'||string=='j'||string=='k'||string=='l'||string=='n'||string=='m') {
        return 1;
    } else {
        return 0;
    }
}