//
//  AOJ0071.c
//  
//
//  Created by n_knuu on 2014/02/27.
//
//

#include <stdio.h>
int main(void) {
    int num,area[8][8],i,j,k,bomb[64][2],sp,bx,by;
    char str[8];
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        sp=0;
        for (j=0; j<8; j++) {
            scanf("%s\n",str);
            for(k=0;k<8;k++) {
                if(str[k]=='0') {
                	area[j][k]=0;
                } else {
                	area[j][k]=1;
                }
            }
        }
        scanf("%d %d",&bx,&by);
        bomb[0][0]=bx-1;
        bomb[0][1]=by-1;
        
        sp++;
        while (1) {
            sp--;
            bx=bomb[sp][0];
            by=bomb[sp][1];
            area[by][bx]=0;
            for (j=bx-1; bx-3<=j&&j>=0; j--) {
                if (area[by][j]==1) {
                    area[by][j]=0;
                    bomb[sp][0]=j;
                    bomb[sp][1]=by;
                    sp++;
                }
            }
            for (j=bx+1; bx+3>=j&&j<=7; j++) {
                if (area[by][j]==1) {
                    area[by][j]=0;
                    bomb[sp][0]=j;
                    bomb[sp][1]=by;
                    sp++;
                }
            }
            for (j=by-1; by-3<=j&&j>=0; j--) {
                if (area[j][bx]==1) {
                    area[j][bx]=0;
                    bomb[sp][0]=bx;
                    bomb[sp][1]=j;
                    sp++;
                }
            }
            for (j=by+1; by+3>=j&&j<=7; j++) {
                if (area[j][bx]==1) {
                    area[j][bx]=0;
                    bomb[sp][0]=bx;
                    bomb[sp][1]=j;
                    sp++;
                }
            }
            if (sp==0) break;
        }
        printf("Data %d:\n",i+1);
        for (j=0; j<8; j++) {
            for(k=0;k<8;k++) printf("%d",area[j][k]);
            printf("\n");
        }
    }
    return 0;
}