//
//  AOJ2501.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
#include <stdlib.h>
int distance(int a,int b,int w);
int main(void) {
    int num,a,b,c,d,i,min=200,temp;
    scanf("%d %d %d %d %d",&num,&a,&b,&c,&d);
    for (i=1; i<=num; i++) {
        temp = distance(a-1,b-1,i)+distance(c-1,d-1,i);
        if (temp<min) min=temp;
    }
    printf("%d\n",min);
    return 0;
}

int distance(int a,int b,int w) {
    return abs(a/w-b/w)+abs(a%w-b%w);
}