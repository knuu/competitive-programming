//
//  AOJ0108.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
int main(void) {
    int num,s[12],p[12],check[10000],i,j,count;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        count=0;
        for (i=0; i<num; i++) scanf("%d",&s[i]);
        for (i=0; ; i++) {
            for (j=1; j<=12; j++) check[j]=0;
            for (j=0; j<num; j++) check[s[j]]++;
            for (j=0; j<num; j++) p[j]=check[s[j]];
            for (j=0; j<num; j++) {
                if (s[j]!=p[j]) break;
            }
            if (j==num) {
                break;
            } else {
                for (j=0; j<num; j++) s[j]=p[j];
            }
        }
        printf("%d\n",i);
        for (i=0; i<num; i++) {
        	if (i) printf(" ");
        	printf("%d",s[i]);
        }
        printf("\n");
    }
    return 0;
}