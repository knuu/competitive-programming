//
//  AOJ0076.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
#include <math.h>
int main(void) {
    int n,p,i;
    double x,y,ans[1001][3];
    for (i=2;i<=1000;i++) {
        ans[i][0]=0.0;
        ans[i][1]=0.0;
        ans[i][2]=0;
    }
    ans[1][0]=1.0;
    ans[1][1]=0.0;
    ans[1][2]=1;
    while (1) {
        scanf("%d",&n);
        if (n==-1) break;
        if (ans[n][2]==1) {
            printf("%lf\n%lf\n",ans[n][0],ans[n][1]);
        } else {
            p=n-1;
            while (ans[p][2]==0) p--;
            x = ans[p][0];
            y = ans[p][1];
            for (i=p+1; i<=n; i++) {
                ans[i][0]= x - y/sqrt(x*x+y*y);
                ans[i][1]= y + x/sqrt(x*x+y*y);
                x=ans[i][0];
                y=ans[i][1];
                ans[i][2]=1;
            }
            printf("%lf\n%lf\n",ans[n][0],ans[n][1]);
        }
    }
    return 0;
}