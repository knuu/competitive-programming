//
//  ITP1-5-B.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int height,width,i,j;
    while (1) {
        scanf("%d %d",&height,&width);
        if (height==0&&width==0) break;
        for (i=0; i<height; i++) {
            for (j=0; j<width; j++) {
                if (i==0||i==height-1||j==0||j==width-1) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}