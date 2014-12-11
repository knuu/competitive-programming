//
//  AOJ0104.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
int main(void) {
    int height,width,tile[101][101],i,j;
    char floor[101][101];
    while (1) {
        scanf("%d %d\n",&height,&width);
        if (height==0&&width==0) break;
        for (i=0; i<height; i++) {
            for (j=0; j<width; j++) tile[i][j]=0;
        }
        for (i=0; i<height; i++) scanf("%s",floor[i]);
        i=0,j=0;
        while (floor[i][j]!='.'&&tile[i][j]!=1) {
            tile[i][j]=1;
            if (floor[i][j]=='>') {
                j++;
            } else if (floor[i][j]=='<') {
                j--;
            } else if (floor[i][j]=='^') {
                i--;
            } else {
                i++;
            }
        }
        if (tile[i][j]==0) {
            printf("%d %d\n",j,i);
        } else {
            printf("LOOP\n");
        }
    }
    return 0;
}