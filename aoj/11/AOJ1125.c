//
//  AOJ1125.c
//  
//
//  Created by n_knuu on 2014/03/17.
//
//


#include <stdio.h>
int main(void) {
    int num,width,height,rect[100][100],i,j,k,l,x,y,s,t,temp,max;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        max=0;
        scanf("%d %d",&width,&height);
        for (i=0; i<height; i++) {
            for (j=0; j<width; j++) rect[i][j]=0;
        }
        for (i=0; i<num; i++) {
            scanf("%d %d",&x,&y);
            rect[x-1][y-1]++;
        }
        /*for (i=0; i<height; i++) {
         for (j=0; j<width; j++) printf("%d ",rect[j][i]);
         printf("\n");
         }*/
        scanf("%d %d",&s,&t);
        for (i=0; i<=height-t; i++) {
            for (j=0; j<=width-s; j++) {
                temp=0;
                for (k=0; k<t; k++) {
                    for (l=0; l<s; l++) {
                        if (rect[j+l][i+k]==1) temp++;
                    }
                }
                //printf("%d,%d %d\n",j,i,temp);
                if (temp>max) max=temp;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}