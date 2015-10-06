//
//  ALDS1-11-A.c
//  
//
//  Created by n_knuu on 2014/03/14.
//
//

#include <stdio.h>
int main(void) {
    int num,adj[100][100]={{0}},u,k,v,i,j,l;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%d %d",&u,&k);
        for (j=0; j<k; j++) {
            scanf("%d",&v);
            adj[u-1][v-1]=1;
        }
    }
    for (i=0; i<num; i++) {
        for (j=0; j<num; j++) {
            if (j) printf(" ");
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}