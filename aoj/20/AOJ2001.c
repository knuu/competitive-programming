//
//  AOJ2001.c
//  
//
//  Created by knuu on 2014/05/18.
//
//

#include <stdio.h>
int main(void) {
    int n,m,a,h,p,q,i,j,flag;
    while (scanf("%d %d %d",&n,&m,&a)!=EOF&&(n!=0||m!=0||a!=0)) {
        int amida[1001][1001][2]={{{0}}};
        for (i=0; i<m; i++) {
            scanf("%d %d %d",&h,&p,&q);
            amida[h][0][0]++;
            amida[h][amida[h][0][0]][0]=p;
            amida[h][amida[h][0][0]][1]=q;
        }
        for (i=1000; i>0; i--) {
            flag=0;
            for (j=1; j<=amida[i][0][0]; j++) {
                if (amida[i][j][0]==a) {
                    flag=2;
                    break;
                } else if (amida[i][j][1]==a) {
                    flag=1;
                    break;
                }
            }
            if (flag!=0) {
                a=amida[i][j][flag-1];
            }
        }
        printf("%d\n",a);
    }
    return 0;
}