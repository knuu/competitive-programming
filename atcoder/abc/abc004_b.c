//
//  ABC004B.c
//  
//
//  Created by n_knuu on 2014/02/16.
//
//

#include <stdio.h>
int main(void){
    int i,n=4;
    char a[n][n];
    for(i=0;i<4;i++) scanf("%c %c %c %c ",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for(i=3;i>=0;i--) printf("%c %c %c %c\n",a[i][3],a[i][2],a[i][1],a[i][0]);
    return 0;

}