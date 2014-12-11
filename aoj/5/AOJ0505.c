//
//  AOJ0505.c
//  
//
//  Created by n_knuu on 2014/05/01.
//
//

#include <stdio.h>
int main(void) {
    int n,m,i,j,temp,place[101][2];
    while (scanf("%d %d",&n,&m)!=EOF&&(m!=0||n!=0)) {
        for (i=0; i<m; i++) {
            place[i][0]=i;
            place[i][1]=0;
        }
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                scanf("%d",&temp);
                place[j][1]+=temp;
            }
        }
        for (i=0; i<m; i++) {
            for (j=0; j<m-i-1; j++) {
                if (place[j][1]<place[j+1][1]) {
                    temp=place[j][1];
                    place[j][1]=place[j+1][1];
                    place[j+1][1]=temp;
                    temp=place[j][0];
                    place[j][0]=place[j+1][0];
                    place[j+1][0]=temp;
                }
            }
        }
        for (i=0; i<m; i++) {
            if (i) printf(" ");
            printf("%d",place[i][0]+1);
        }
        printf("\n");
    }
    return 0;
}