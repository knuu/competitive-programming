//
//  ALDS1-1-A.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    int num,array[100],i,j,key;
    scanf("%d",&num);
    for (i=0; i<num; i++) scanf("%d",&array[i]);
    for (i=0; i<num; i++) {
        if (i) printf(" ");
        printf("%d",array[i]);
    }
    printf("\n");
    for (i=1; i<num; i++) {
        key=array[i];
        for (j=i-1; j>=0&&array[j]>key; j--) array[j+1]=array[j];
        array[j+1]=key;
        for (j=0; j<num; j++) {
            if (j) printf(" ");
            printf("%d",array[j]);
        }
        printf("\n");
    }
    return 0;
}