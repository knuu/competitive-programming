//
//  ALDS1-1-C.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int num,temp,i,j,count=0;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%d",&temp);
        for (j=2; j<=sqrt(temp); j++) {
            if (temp%j==0) break;
        }
        if (j>sqrt(temp)||sqrt(temp)<2) count++;
    }
    printf("%d\n",count);
    return 0;
}