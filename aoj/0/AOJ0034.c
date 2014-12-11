//
//  AOJ0034.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int l[10],v[2],L=0,ans[100],temp,i,j=0;
    float cp;
    while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&l[0],&l[1],&l[2],&l[3],&l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v[0],&v[1])!=EOF) {
        L=0;
        for(i=0;i<10;i++) L+=l[i];
        cp = 1.0*L*v[0]/(v[0]+v[1]);
        for(i=0;i<10;i++) {
            cp -= l[i];
            if(cp<=0) {
                ans[j]=i+1;
                break;
            }
        }
        j++;
    }
    for(i=0;i<j;i++) printf("%d\n",ans[i]);
    return 0;
}