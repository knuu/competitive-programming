//
//  AOJ2407.c
//  
//
//  Created by n_knuu on 2014/03/07.
//
//

#include <stdio.h>
int main(void) {
    char board[51];
    scanf("%s",board);
    if (board[0]==board[strlen(board)-1]) {
        printf("%c\n",board[0]);
    } else {
        printf("o\n");
    }
    return 0;
}