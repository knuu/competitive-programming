//
//  AOJ0030.c
//  
//
//  Created by n_knuu on 2014/02/28.
//
//

#include <stdio.h>
int main(void) {
    int num,sum,ans[45],i,j,k,l,m;
    while (1) {
        scanf("%d %d\n",&num,&sum);
        if (num==0&&sum==0) break;
        if (sum>num*(19-num)/2||sum<num*(num-1)/2) {
            printf("0\n");
            continue;
        }
        for (i=0; i<45; i++) ans[i]=0;
        switch (num) {
            case 1:
                for (i=0; i<=9; i++) ans[i]++;
                break;
                
            case 2:
                for (i=0; i<=8; i++) {
                    for (j=i+1; j<=9; j++) ans[i+j]++;
                }
                break;
                
            case 3:
                for (i=0; i<=7; i++) {
                    for (j=i+1; j<=8; j++) {
                        for (k=j+1; k<=9; k++) ans[i+j+k]++;
                    }
                }
                break;
                
            case 4:
                for (i=0; i<=6; i++) {
                    for (j=i+1; j<=7; j++) {
                        for (k=j+1; k<=8; k++) {
                            for (l=k+1; l<=9; l++) ans[i+j+k+l]++;
                        }
                    }
                }
                break;
                
            case 5:
                for (i=0; i<=5; i++) {
                    for (j=i+1; j<=6; j++) {
                        for (k=j+1; k<=7; k++) {
                            for (l=k+1; l<=8; l++) {
                                for (m=l+1; m<=9; m++) ans[i+j+k+l+m]++;
                            }
                        }
                    }
                }
                break;

                
            case 6:
                for (i=0; i<=6; i++) {
                    for (j=i+1; j<=7; j++) {
                        for (k=j+1; k<=8; k++) {
                            for (l=k+1; l<=9; l++) ans[45-(i+j+k+l)]++;
                        }
                    }
                }
                break;
                
            case 7:
                for (i=0; i<=7; i++) {
                    for (j=i+1; j<=8; j++) {
                        for (k=j+1; k<=9; k++) ans[45-(i+j+k)]++;
                    }
                }
                break;
                
            case 8:
                for (i=0; i<=8; i++) {
                    for (j=i+1; j<=9; j++) ans[45-(i+j)]++;
                }
                break;

            case 9:
                for (i=0; i<=9; i++) ans[45-i]++;
                break;
        }
        printf("%d\n",ans[sum]);
    }
    return 0;
}