//
//  AOJ0133.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int i,j;
    char board[8][8];
    for (i=0; i<8; i++) scanf("%s\n",board[i]);
    printf("90\n");
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) printf("%c",board[7-j][i]);
        printf("\n");
    }
    printf("180\n");
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) printf("%c",board[7-i][7-j]);
        printf("\n");
    }
    printf("270\n");
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) printf("%c",board[j][7-i]);
        printf("\n");
    }
    return 0;
}