//
//  ALDS1-2-B.c
//  
//
//  Created by knuu on 2014/04/22.
//
//

#include <stdio.h>
int main(void) {
    int i,j,min,num,temp,count=0,array[101];
    scanf("%d",&num);
    for (i=0; i<num; i++) scanf("%d",&array[i]);
    for (i=0; i<num; i++) {
        min = i;
        for (j=i; j<num; j++) {
            if (array[j]<array[min]) min = j;
        }
        if (i!=min) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            count++;
        }
    }
    for (i=0; i<num; i++) {
        if (i) printf(" ");
        printf("%d",array[i]);
    }
    printf("\n%d\n",count);
    return 0;
}