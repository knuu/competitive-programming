//
//  AOJ1153.c
//  
//
//  Created by n_knuu on 2014/03/16.
//
//

#include <stdio.h>
int main(void) {
    int nt,nh,i,temp;
    while (1) {
        scanf("%d %d",&nt,&nh);
        if (nt==0&&nh==0) break;
        int ct[101]={0},ch[101]={0},st=0,sh=0,flag[2]={0};
        for (i=0; i<nt; i++) {
            scanf("%d",&temp);
            st+=temp;
            ct[temp]=1;
        }
        for (i=0; i<nh; i++) {
            scanf("%d",&temp);
            sh+=temp;
            ch[temp]=1;
        }
        if ((st+sh)%2==1) {
            printf("-1\n");
            continue;
        }
        if (nt<nh) {
            for (i=1; i<=100; i++) {
                if (ct[i]==1&&ch[(sh-st)/2+i]==1) {
                    flag[0]=i,flag[1]=(sh-st)/2+i;
                    break;
                }
            }
        } else {
            for (i=1; i<=100; i++) {
                if (ch[i]==1&&ct[(st-sh)/2+i]==1) {
                    flag[0]=(st-sh)/2+i,flag[1]=i;
                    break;
                }
            }
        }
        if (flag[0]==0) {
            printf("-1\n");
        } else {
            printf("%d %d\n",flag[0],flag[1]);
        }
    }
    return 0;
}