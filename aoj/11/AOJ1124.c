//
//  AOJ1124.c
//  
//
//  Created by n_knuu on 2014/03/17.
//
//

#include <stdio.h>
int main(void) {
    int num,quorum,m,i,j,temp;
    while (1) {
        scanf("%d %d",&num,&quorum);
        if (num==0&&quorum==0) break;
        int date[50][101]={{0}},last=0,max=0,day=0;
        for (i=0; i<num; i++) {
            scanf("%d",&m);
            for (j=0; j<m; j++) {
                scanf("%d",&temp);
                date[i][temp]++;
                if (temp>last) last=temp;
            }
        }
        for (i=1; i<=last; i++) {
            temp=0;
            for (j=0; j<num; j++) if (date[j][i]==1) temp++;
            if (temp>=quorum&&temp>max) {
                max=temp;
                day=i;
            }
        }
        printf("%d\n",day);
    }
    return 0;
}