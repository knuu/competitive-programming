//
//  AOJ10029.c
//  
//
//  Created by knuu on 2014/05/18.
//
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
int compare(const void *a1, const void *a2);
int main(void) {
    int i,num,array[MAX];
    scanf("%d",&n);
    for (i=0; i<num; i++) scanf("%d",&array[i]);
    qsort(array,num,sizeof(int),compare);
    for (i=0; i<num; i++) {
        if (i) printf(" ");
        printf("%d",array[i]);
    }
    printf("\n");
    return 0;
}

int compare(const void *a1, const void *a2) {
    return (*((int *) a1)-*((int *) a2));
}