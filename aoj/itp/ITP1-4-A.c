//
//  ITP1-4-A.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d %lf\n",a/b,a%b,1.0*a/b);
    return 0;
}