//
//  AOJ0148.c
//  
//
//  Created by n_knuu on 2014/03/31.
//
//

#include <stdio.h>
int main(void) {
    int num;
    while (scanf("%d",&num)!=EOF) {
    	num%=39;
    	if (num==0) num=39;
    	printf("3C%02d\n",num);
    }
    return 0;
}