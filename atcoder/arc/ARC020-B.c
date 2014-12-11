//
//  ARC20-2.c
//  
//
//  Created by n_knuu on 2014/03/29.
//
//

#include <stdio.h>
int main(void) {
    int n,c,a[100],odd[11]={0},even[11]={0},of=0,os=0,ef=0,es=0,i;
    scanf("%d %d",&n,&c);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if (i%2==0) {
            even[a[i]]++;
        } else {
            odd[a[i]]++;
        }
    }
    if (n==2) {
        if (a[0]==a[1]) {
            printf("%d\n",c);
            return 0;
        } else {
            printf("0\n");
            return 0;
        }
    } else if (n==3) {
        if (a[0]==a[1]||a[0]!=a[2]) {
            printf("%d\n",c);
        } else {
            printf("0\n");
        }
    }
    for (i=1; i<=10; i++) {
        if (even[i]>even[ef]) {
            ef = i;
        } else if (even[i]>even[es]) {
            es = i;
        }
        if (odd[i]>odd[of]) {
            of = i;
        } else if (odd[i]>odd[os]) {
            os = i;
        }
    }
    if (os==0&&es==0) {
        printf("%d\n",n*c/2);
        return 0;
    } else if (
    if (n%2==0) {
        if (ef!=es) {
            printf("%d\n",)
        }
    }
    
}