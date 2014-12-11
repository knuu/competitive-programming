//
//  AOJ0051.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char array[8];
    int num,i,j,k;
    char reverse[8],temp;
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        scanf("%s\n",array);
        for (j=0; j<8; j++) {
            for (k=0; k<7-j; k++) {
                if (array[k]>array[k+1]) {
                    temp=array[k];
                    array[k]=array[k+1];
                    array[k+1]=temp;
                }
            }
        }
        for (j=0; j<8; j++) reverse[j]=array[7-j];
        printf("%d\n",atoi(reverse)-atoi(array));
    }
    return 0;
}