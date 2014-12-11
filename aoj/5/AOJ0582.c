//
//  AOJ0582.c
//  
//
//  Created by n_knuu on 2014/03/30.
//
//

#include <stdio.h>
int main(void) {
    int a,b,c,temp,i,ob=0,ac=0,ri=0,cosA;
    for (i=0; ; i++) {
        scanf("%d%d%d",&a,&b,&c);
        if (b>a) {
            temp=b;
            b=a;
            a=temp;
        }
        if (c>a) {
            temp=c;
            c=a;
            a=temp;
        }
        if (b+c<=a) break;
        cosA=b*b+c*c-a*a;
        if (cosA>0) {
            ac++;
        } else if (cosA<0) {
            ob++;
        } else {
            ri++;
        }
    }
    printf("%d %d %d %d\n",i,ri,ac,ob);
    return 0;
}