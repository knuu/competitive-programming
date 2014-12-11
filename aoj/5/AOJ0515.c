//
//  AOJ0515.c
//  
//
//  Created by n_knuu on 2014/05/01.
//
//

#include <stdio.h>
int main(void) {
    int a,b,n,i,j,x,y;
    while (scanf("%d %d",&a,&b)!=EOF&&(a!=0||b!=0)) {
        int map[18][18]={{0}};
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            scanf("%d %d",&x,&y);
            map[x][y]=-1;
        }
        if (map[1][1]==-1) {
            printf("0\n");
            continue;
        } else {
            map[1][1]=1;
        }
        for (i=1; i<=a; i++) {
            for (j=1; j<=b; j++) {
                if (map[i][j]==-1) {
                    map[i][j]=0;
                } else {
                    map[i][j]+=map[i-1][j]+map[i][j-1];
                }
            }
        }
        printf("%d\n",map[a][b]);
    }
    return 0;
}