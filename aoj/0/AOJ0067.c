//
//  AOJ0067.c
//  
//
//  Created by n_knuu on 2014/03/21.
//
//

#include <stdio.h>
int main(void) {
    int map[14][14][2]={{{0}}},i,j,count;
    char temp;
    while (scanf(" %c",&temp)!=EOF) {
        for (i=1; i<=12; i++) {
            for (j=1; j<=12; j++) {
                if (i==1&&j==1) {
                    map[1][1][0]=temp-'0';
                    map[1][1][1]=0;
                } else {
                    scanf(" %c",&temp);
                    map[i][j][0]=temp-'0';
                    map[i][j][1]=0;
                }
            }
        }
        count=0;
        for (i=1; i<=12; i++) {
            for (j=1; j<=12; j++) {
                if (map[i][j][0]==1) {
                    if (map[i-1][j][1]==0&&map[i][j-1][1]==0&&map[i+1][j][1]==0&&map[i][j+1][1]==0) {
                        count++;
                        map[i][j][1]=1
                        if (map[i-1][j][0]==1) map[i-1][j][1]=1;
                        if (map[i][j-1][0]==1) map[i][j-1][1]=1;
                        if (map[i+1][j][0]==1) map[i+1][j][1]=1;
                        if (map[i][j+1][0]==1) map[i][j+1][1]=1;
                    } else if (map[i][j][1]==1) {
                        if (map[i-1][j][0]==1) map[i-1][j][1]=1;
                        if (map[i][j-1][0]==1) map[i][j-1][1]=1;
                        if (map[i+1][j][0]==1) map[i+1][j][1]=1;
                        if (map[i][j+1][0]==1) map[i][j+1][1]=1;
                    } else {
                        map[i][j][1]=1
                        if (map[i-1][j][0]==1) map[i-1][j][1]=1;
                        if (map[i][j-1][0]==1) map[i][j-1][1]=1;
                        if (map[i+1][j][0]==1) map[i+1][j][1]=1;
                        if (map[i][j+1][0]==1) map[i][j+1][1]=1;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}