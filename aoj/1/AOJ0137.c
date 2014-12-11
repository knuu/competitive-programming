//
//  AOJ0137.c
//  
//
//  Created by n_knuu on 2014/04/11.
//
//

#include <stdio.h>
int main(void) {
    int s,i,j,k,num;
    char t[9];
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%d",&s);
        printf("Case %d:\n",i+1);
        for (j=0; j<10; j++) {
        	s=s*s;
            sprintf(t,"%08d",s);
            s=(t[5]-'0')+(t[4]-'0')*10+(t[3]-'0')*100+(t[2]-'0')*1000;
            printf("%d\n",s);
        }
    }
    return 0;
}