//
//  AOJ0110.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    int add1,add2,sum,i,j;
    char str1[127],copy[127],str2[127],a[10]={'0','1','2','3','4','5','6','7','8','9'};
    while (scanf("%s\n",str1)!=EOF) {
        for (i=0; i<10; i++) {
            strcpy(copy,str1);
            for (j=0; j<strlen(copy); j++) {
                if (copy[j]=='X') {
                    copy[j]=a[i];
                }
            }
            sscanf(copy,"%d+%d=%d",&add1,&add2,&sum);
            sprintf(str2,"%d+%d=%d",add1,add2,sum);
            if (strlen(str1)!=strlen(str2)) continue;
            if (add1+add2==sum) break;
        }
        if (i==10) {
            printf("NA\n");
        } else {
            printf("%d\n",i);
        }
    }
    return 0;
}