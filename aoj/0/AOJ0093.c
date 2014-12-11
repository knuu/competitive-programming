//
//  AOJ0093.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
int main(void){
    int a,b,ans[750],i,j=0,p;
    while (1) {
        ans[0]=0;
        p=0;
        scanf("%d %d",&a,&b);
        if (a==0&&b==0) break;
        for(i=a;i<=b;){
            if(i%4==0){
                if(i%100!=0||i%400==0) {
                	ans[p]=i;
                	p++;
                }
                i+=4;
            } else {
                i++;
            }
        }
        if (j!=0) printf("\n");
        if (ans[0]==0) {
            printf("NA\n");
        } else {
            for(i=0;i<p;i++) printf("%d\n",ans[i]);
        }
        j++;
    }
    return 0;
}