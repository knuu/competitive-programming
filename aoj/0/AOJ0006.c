//
//  AOJ0006.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    char str[20];
    int i=0,j;
    while(scanf("%c",&str[i])!=EOF) i++;
    for(j=i-2;j>=0;j--) printf("%c",str[j]);
    printf("\n");
    return 0;
}