//
//  AOJ0029.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int sp=0,count[500]={0},i=0,maxlen[2]={0},max[2]={0};
    char word[500][32],temp[32];
    while (scanf(" %s",&temp)!=EOF) {
        if (sp==0) {
            strcpy(word[sp],temp);
            count[sp]++;
            maxlen[1]=strlen(word[sp]);
            maxlen[0]=sp;
            sp++;
        } else {
            for (i=0; i<sp; i++) if (strcmp(word[i],temp)==0) break;
            if (i==sp) {
                strcpy(word[sp],temp);
                count[sp]++;
                if (strlen(word[sp])>maxlen[1]) {
                    maxlen[0]=sp;
                    maxlen[1]=strlen(word[sp]);
                }
                sp++;
            } else {
                count[i]++;
            }
        }
    }
    for (i=0; i<sp; i++) {
        if (count[i]>max[1]) {
            max[1]=count[i];
            max[0]=i;
        }
    }
    printf("%s %s\n",word[max[0]],word[maxlen[0]]);
    return 0;
}