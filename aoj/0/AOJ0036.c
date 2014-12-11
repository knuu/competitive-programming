//
//  AOJ0036.c
//  
//
//  Created by knuu on 2014/05/01.
//
//

#include <stdio.h>
int main(void) {
    int i,j;
    char board[9][9];
    while (scanf(" %s\n",board[0])!=EOF) {
        for (i=1; i<8; i++) scanf(" %s",board[i]);
        for (i=0; ; i++) {
            for (j=0; j<8; j++) {
            	if (board[i][j]=='1') break;
            }
            if (board[i][j]=='1') break;
        }
        if (i<7&&j<7&&board[i][j+1]=='1'&&board[i+1][j]=='1'&&board[i+1][j+1]=='1') printf("A\n");
        if (i<5&&board[i+1][j]=='1'&&board[i+2][j]=='1'&&board[i+3][j]=='1') printf("B\n");
        if (j<5&&board[i][j+1]=='1'&&board[i][j+2]=='1'&&board[i][j+3]=='1') printf("C\n");
        if (i<6&&j>0&&board[i+1][j]=='1'&&board[i+1][j-1]=='1'&&board[i+2][j-1]=='1') printf("D\n");
        if (i<7&&j<6&&board[i][j+1]=='1'&&board[i+1][j+1]=='1'&&board[i+1][j+2]=='1') printf("E\n");
        if (i<6&&j<7&&board[i+1][j]=='1'&&board[i+1][j+1]=='1'&&board[i+2][j+1]=='1') printf("F\n");
        if (i<7&&j>0&&j<7&&board[i][j+1]=='1'&&board[i+1][j]=='1'&&board[i+1][j-1]=='1') printf("G\n");
    }
    return 0;
}