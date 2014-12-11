//
//  AOJ0092.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
int main(void) {
    int num,i,j,count,k,l,check[1000][1000],m,n;
    char board[1000][1000];
    while (1) {
        scanf("%d¥n",&num);
        if (num==0) break;
        count=0;
        for (i=0; i<num; i++) {
         for (j=0; j<num ;j++) check[i][j]=0;
         }
        for (i=0; i<num; i++) scanf("%s\n",board[i]);
        for (i=0; i<num; i++) {
            for (j=0; j<num; j++) {
                if (board[i][j]=='.'&&check[i][j]==0) {
                    for (k=0; k+i<num&&k+j<num; k++) {
                        for (l=0; l<=k; l++) {
                            if (board[i+k][j+l]=='*') {
                                for (m=i; m<=i+k; m++) {
                                    for (n=j; n<j+l; n++) check[m][n]=1;
                                }
                                j+=l
                                break;
                            }
                            if (board[i+l][j+k]=='*') {
                                for (m=i; m<=i+l; m++) {
                                    for (n=j; n<j+k; n++) check[m][n]=1;
                                }
                                j+=k;
                                break;
                            }
                        }
                        if (l!=k+1) break;
                    }
                    if (k>count) count=k;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}