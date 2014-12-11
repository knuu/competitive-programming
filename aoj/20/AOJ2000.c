//
//  AOJ2000.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
int main(void) {
    int num,inum,stack[20][2],sp,map[21][21],i,j,step,x,y;
    char dir;
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        x=10,y=10;
        for (i=0; i<=20; i++) {
            for (j=0; j<=20; j++) map[i][j]=0;
        }
        for (sp=0; sp<num; sp++) scanf("%d %d\n",&stack[sp][0],&stack[sp][1]);
        scanf("%d\n",&inum);
        for (i=0; i<inum; i++) {
            scanf("%c %d\n",&dir,&step);
            if (dir=='N') {
                for (j=0; j<=step; j++) map[x][y+j]=1;
                y+=step;
            } else if (dir=='E') {
                for (j=0; j<=step; j++) map[x+j][y]=1;
                x+=step;
            } else if (dir=='S') {
                for (j=0; j<=step; j++) map[x][y-j]=1;
                y-=step;
            } else if (dir=='W') {
                for (j=0; j<=step; j++) map[x-j][y]=1;
                x-=step;
            }
        }
        for (i=0; i<sp; i++) {
            if (map[stack[i][0]][stack[i][1]]==0) break;
        }
        if (i==sp) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}